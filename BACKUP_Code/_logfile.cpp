#include "Header.h"

/**
 * @author foxcode01
 */

// Global var for time
string dateTimeFileLog = "YYYYMMDD_HHMMSS_";				// for the file name
string dateTimeLog = "DD.MM.YYYY um HH:MM:SS Uhr";			// for the time informations


// Path for all the logfiles
string driveForLog = "";
string folderForLog = "";

// Filenames for the logs
string fileForLog			= "log";
string fileForLogWarning	= "log_warning";
string fileForLogError		= "log_error";
string fileForLogSysError	= "log_syserror";
string fileForLogMessage	= "log_message";
string fileForLogInfo		= "log_info";

// Path for the logs
string pathLog = "";
string pathLogWarning = "";
string pathLogError = "";
string pathLogSysError = "";
string pathLogMessage = "";
string pathLogInfo = "";

// Path for the temp logs
string tempPathLog = "";
string tempPathLogWarning = "";
string tempPathLogError = "";
string tempPathLogSysError = "";
string tempPathLogMessage = "";
string tempPathLogInfo = "";


void timeInLog(string date, string time, string year, string month, string day, string hour, string minute, string sec) {
	dateTimeFileLog = date + "_" + time + "_";
	dateTimeLog = day + "." + month + "." + year + " um " + hour + ":" + minute + ":" + sec + " Uhr: ";
}


void startLog(string tempDriveForLog, string tempFolderForLog) {
	getTime();

	driveForLog = tempDriveForLog;
	folderForLog = tempFolderForLog;

	pathLog			= driveForLog + ":\\" + folderForLog + "\\" + fileForLog + ".txt";
	pathLogWarning	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogWarning + ".txt";
	pathLogError	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogError + ".txt";
	pathLogSysError = driveForLog + ":\\" + folderForLog + "\\" + fileForLogSysError + ".txt";
	pathLogMessage	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogMessage + ".txt";
	pathLogInfo		= driveForLog + ":\\" + folderForLog + "\\" + fileForLogInfo + ".txt";

	tempPathLog			= driveForLog + ":\\" + folderForLog + "\\" + fileForLog + "\\" + dateTimeFileLog + fileForLog + ".txt";
	tempPathLogWarning	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogWarning + "\\" + dateTimeFileLog + fileForLogWarning + ".txt";
	tempPathLogError	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogError + "\\" + dateTimeFileLog + fileForLogError + ".txt";
	tempPathLogSysError = driveForLog + ":\\" + folderForLog + "\\" + fileForLogSysError + "\\" + dateTimeFileLog + fileForLogSysError + ".txt";
	tempPathLogMessage	= driveForLog + ":\\" + folderForLog + "\\" + fileForLogMessage + "\\" + dateTimeFileLog + fileForLogMessage + ".txt";
	tempPathLogInfo		= driveForLog + ":\\" + folderForLog + "\\" + fileForLogInfo + "\\" + dateTimeFileLog + fileForLogInfo + ".txt";
}


void logInfo(string logfilePath, string content) {
	string line;
	string logContent = "";

	//Read existing logfile
	ifstream tempLogfile(logfilePath);

	if (tempLogfile.is_open()) {
		while (getline(tempLogfile, line)) {
			logContent = logContent + line + "\n";
		}
		tempLogfile.close();
	}

	//cout << logContent;									// Output in the console

	content = logContent + dateTimeFileLog + content;

	//Update the logfile
	ofstream updateLogfile;

	updateLogfile.open(logfilePath);
	updateLogfile << content;
	updateLogfile.close();
}


void logMsg(int consoleOutputSelect, string kind, string content) {
	if (kind == "warning") {
		string contentLog = "WARNING: " + content;

		logInfo(pathLog, contentLog);
		logInfo(tempPathLog, contentLog);
		logInfo(pathLogWarning, content);
		logInfo(tempPathLogWarning, content);

		if (consoleOutputSelect == 1) {
			cout << endl
				<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
				<< dateTimeLog << endl
				<< content << endl
				<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
				<< endl;
		}
	}

	else if (kind == "error") {
		string contentLog = "ERROR: " + content;

		logInfo(pathLog, contentLog);
		logInfo(tempPathLog, contentLog);
		logInfo(pathLogError, content);
		logInfo(tempPathLogError, content);

		if (consoleOutputSelect == 1) {
			cout << endl
				<< "---------------------------------------E R R O R----------------------------------------" << endl
				<< dateTimeLog << endl
				<< content << endl
				<< "---------------------------------------E R R O R----------------------------------------" << endl
				<< endl;
		}
	}

	else if (kind == "sysError") {
		string contentLog = "SYTEMERROR: " + content;

		logInfo(pathLog, contentLog);
		logInfo(tempPathLog, contentLog);
		logInfo(pathLogSysError, content);
		logInfo(tempPathLogSysError, content);

		if (consoleOutputSelect == 1) {
			cout << endl
				<< "---------------------------------S Y S T E M E R R O R----------------------------------" << endl
				<< dateTimeLog << endl
				<< content << endl
				<< "---------------------------------S Y S T E M E R R O R----------------------------------" << endl
				<< endl;
		}
	}

	else if (kind == "message") {
		string contentLog = "MESSAGE: " + content;

		logInfo(pathLog, contentLog);
		logInfo(tempPathLog, contentLog);
		logInfo(pathLogMessage, content);
		logInfo(tempPathLogMessage, content);

		if (consoleOutputSelect == 1) {
			cout << endl
				<< "****************************************************************************************" << endl
				<< content << endl
				<< "****************************************************************************************" << endl
				<< endl;
		}
	}

	else if (kind == "info") {
		string contentLog = "INFO: " + content;

		logInfo(pathLog, contentLog);
		logInfo(tempPathLog, contentLog);
		logInfo(pathLogInfo, content);
		logInfo(tempPathLogInfo, content);

		if (consoleOutputSelect == 1) {
			cout << endl
				<< "########################################################################################" << endl
				<< content << endl
				<< "########################################################################################" << endl
				<< endl;
		}
	}

	else {
		logInfo(pathLog, "SYSTEMERROR: Logfile konnte keinem Typ zugeordnet werden");
		logInfo(tempPathLog, "SYSTEMERROR: Logfile konnte keinem Typ zugeordnet werden");
		logInfo(pathLogSysError, "Logfile konnte keinem Typ zugeordnet werden");
		logInfo(tempPathLogSysError, "Logfile konnte keinem Typ zugeordnet werden");
	}
}