#pragma once

#include <iostream>
#include <fstream>				//fuer Dateien
#include <string>
#include <windows.h>			//Windows-Funktionen verwenden

/**
 * @author foxcode01
 */

using namespace std;

//*****Standard functions*****
void getTime();

void timeInLog(string date, string time, string year, string month, string day, string hour, string minute, string sec);
void timeInfFile(string date, string time, string year, string month, string day, string hour, string minute, string sec);

void startLog(string tempDriveForLog, string tempFolderForLog);
void startReadWrite(string tempDrive, string tempFolder, string tempDriveForBackup, string tempFolderForBackup);

void logMsg(int consoleOutputSelect, string kind, string content);

int generateFilePath(int chooseDate, string tempDrive, string tempFolder, string filename);
void readAndWriteBackupFile(string file);

void writeFile(int chooseDate, int msg, string tempDrive, string tempFolder, string filename, string filecontent);
void readFile(int msg, string tempDrive, string tempFolder, string filename);


//*****Project functions*****
void exampleReadWriteFile();


// Color Codes:
/*
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/