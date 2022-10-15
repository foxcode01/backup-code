#include "Header.h"

/**
 * @author foxcode01
 * 
 * A backup code for "debugging" simple C++ programs and creating log files.
 * In addition, a backup of the project with a time stamp is created.
 */

string myDrive = "C";																	// drive
string myFolder = "_generatedFiles";													// folder Name

string myDriveForBackup = "C";															// drive for the backups
string myFolderForBackup = "_BACKUP_Code\\_VS_Backup_BACKUP_Code";						// folder Name for the backups

string myDriveForLog = "C";
string myFolderForLog = "_BACKUP_Code\\_VS_Log_BACKUP_Code";

void startBackupCode() {
	system("cls");
	cout << "Backup wird ausgefuehrt..." << endl;

	// Headerdateien
	readAndWriteBackupFile("Header.h");

	// Quelldateien
	readAndWriteBackupFile("_getTime.cpp");
	readAndWriteBackupFile("_readWriteFile.cpp");
	readAndWriteBackupFile("_logfile.cpp");

	readAndWriteBackupFile("exampleReadWriteFile.cpp");

	readAndWriteBackupFile("myBackup.cpp");

	cout << "Backup wurde ausgefuehrt!" << endl;
	Sleep(1000);
	system("cls");
}

int main() {
	startLog(myDriveForLog, myFolderForLog);											// Wichtig, um Logfiles richtig erstellen zu koennen
	startReadWrite(myDrive, myFolder, myDriveForBackup, myFolderForBackup);				// Wichtig um Backups richtig erstellen zu koennen

	startBackupCode();


	system("color 07");
	//cin.sync();

	exampleReadWriteFile();
	//getTime();

	//Sleep(5000);
	cin.get();								// Fenster offen halten
}