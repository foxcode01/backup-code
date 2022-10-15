#include "Header.h"

/**
 * @author foxcode01
 */

string dateTimeFile = "YYYYMMDD_HHMMSS_";											// time informations for the file name
string dateTime = "DD.MM.YYYY um HH:MM:SS Uhr";										// time informations

string drive = "";																	// drive
string folder = "";																	// folder Name

string driveForBackup = "";															// drive for the backups
string folderForBackup = "";														// folder Name for the backups

string filePath = "";																// create a global var for the file path



void startReadWrite(string tempDrive, string tempFolder, string tempDriveForBackup, string tempFolderForBackup) {
	drive = tempDrive;
	folder = tempFolder;

	driveForBackup = tempDriveForBackup;
	folderForBackup = tempFolderForBackup;
}


// Time informations for the file
void timeInfFile(string date, string time, string year, string month, string day, string hour, string minute, string sec) {
	dateTimeFile = date + "_" + time + "_";
	dateTime = day + "." + month + "." + year + " um " + hour + ":" + minute + ":" + sec + " Uhr";

	//cout << endl << "dateTimeFile: " << dateTimeFile << endl;
	//cout << endl << "dateTime: " << dateTime << endl;
}


// Create message for the user with the file informations
void msgFile(int select, string tempFilePath, string inf1, string inf2) {
	string path = "";

	if (tempFilePath == "") {
		path = filePath;
	}
	else {
		path = tempFilePath;
	}

	string msg = inf1 + " " + path + " " + inf2;

	if (select == 1) {
		logMsg(1, "message", msg);
	}
	else if (select == 2) {
		logMsg(1, "warning", msg);
	}
	else {
		logMsg(0, "message", "Keine Ausgabe in der Konsole erwuenscht");
	}
}


// Security query whether the specified file path exists
int askPath(string partPath, string path) {
	char queryPath = '0';

	msgFile(2, partPath, "Existiert der Dateipfad", "wirklich?");

	cout << "y = Ja" << endl << "n = No" << endl << "-> ";
	cin >> queryPath;

	if (queryPath == 'y') {
		filePath = path;
		msgFile(1, filePath, "Der Dateipfad", "wurde generiert");
		return 1;
	}
	else if (queryPath == 'n') {
		msgFile(2, path, "Der Dateipfad", "wurde nicht verwendet!");
		return 0;
	}
	else {
		logMsg(1, "warning", "Bitte entscheiden Sie sich! Probieren Sie es noch einmal");
		askPath(partPath, path);
	}
}


// Generate the file path
int generateFilePath(int chooseDate, string tempDrive, string tempFolder, string filename) {
	if (tempDrive == "") {
		tempDrive = drive;
	}

	if (tempFolder == "") {
		tempFolder = folder;
	}

	if (chooseDate == 0) {
		dateTimeFile = "";
	}
	else if (chooseDate == 1) {
		getTime();
	}
	else {
		logMsg(0, "error", "Auswahl ob ein Datum verwendet werden soll oder nicht");
	}


	if (tempDrive == drive && tempFolder == folder) {
		filePath = drive + ":\\" + folder + "\\" + dateTimeFile + filename;
		//logMsg(0, "info", "STANDARD-Pfad: "+ filePath);
	}
	else if (tempDrive == driveForBackup && tempFolder == folderForBackup) {
		filePath = driveForBackup + ":\\" + folderForBackup + "\\" + dateTimeFile + filename;
		//logMsg(0, "info", "BACKUP-Pfad: " + filePath);
	}
	else {
		string tempPartFilePath = tempDrive + ":\\" + tempFolder + "\\...";
		string tempFilePath = tempDrive + ":\\" + tempFolder + "\\" + dateTimeFile + filename;

		if (askPath(tempPartFilePath, tempFilePath) == 0) {
			logMsg(0, "info", "Es wurde sich fuer nein entschieden");
			return 0;
		}
		else if (askPath(tempPartFilePath, tempFilePath) == 1) {
			logMsg(0, "info", "Es wurde sich fuer ja entschieden");
			return 1;
		}
		else {
			logMsg(1, "error", "Der Rueckgabewert fuer die Auswahl ob ein Dateipfad existiert ist unklar!");
		}
	}
}


// Write a File for '.txt' or '.h' or '.cpp' or '.c' -files
void writeFile(int chooseDate, int msg, string tempDrive, string tempFolder, string filename, string filecontent) {
	generateFilePath(chooseDate, tempDrive, tempFolder, filename);

	if (generateFilePath(chooseDate, tempDrive, tempFolder, filename) == 0) {
		logMsg(1, "error", "Fehler bei der Pfaderstellung");
	}
	else{
		ofstream file;
		file.open(filePath);
		file << "//***** " << dateTime << " *****" << endl << filecontent;
		file.close();

		if (msg > 0 && msg <= 2) {
			msgFile(msg, filePath, "Die Datei wurde unter", "abgespeichert");
		}

		logMsg(0, "info", "Die Datei wurde beschrieben (" + filePath + ")");
	}
}


// Read a File
void readFile(int msg, string tempDrive, string tempFolder, string filename) {
	string line = "";
	string content = "";

	generateFilePath(0, tempDrive, tempFolder, filename);

	if (msg > 0 && msg <= 2) {
		msgFile(msg, filePath, "Die Datei", "wird geoeffnet!");
	}

	ifstream tempFile(filePath);

	if (tempFile.is_open()) {
		while (getline(tempFile, line)) {
			content = content + "\n" + line;
		}
		tempFile.close();
	}
	else {
		string tempMsg = "Die Datei " + filePath + " konnte nicht geoeffnet werden!";
		logMsg(1, "error", tempMsg);
	}

	logMsg(0, "info", "Die Datei " + filePath + " wurde ausgelesen");
	cout << content << endl << endl;
}


// Creates backup files
void readAndWriteBackupFile(string file) {
	getTime();

	string content = "// Backup\n";
	string line = "";

	ifstream backupFile(file);

	if (backupFile.is_open()) {
		while (getline(backupFile, line)) {
			content = content + "\n" + line;
		}
		backupFile.close();
	}
	else {
		string tempMsg = "Die Datei" + file + "konnte nicht geoeffnet werden, dadurch war kein Backup moeglich!";
		logMsg(1, "error", tempMsg);
	}

	writeFile(1, 0, driveForBackup, folderForBackup, file, content);
	logMsg(0, "info", "Backup wurde erstellt");
}