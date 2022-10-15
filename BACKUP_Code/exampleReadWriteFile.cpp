#include "Header.h"

/**
 * @author foxcode01
 */

void exampleReadWriteFile() {
	string myDrive = "";
	string myFolder = "";
	string myFile = "";
	string myText = "";

	cout << "Herzlich Willkommen im Beispielprogramm fuer das Lesen und beschreiben einer Datei!" << endl
		<< "Wenn Sie bei dem Laufwerk oder beim Ordner nichts angeben moechten, dann geben Sie 0 ein!" << endl
		<< "Zuerst wird eine ausgewaehlte Datei beschrieben!" << endl;

	// Datei beschreiben
	cout << endl << "Laufwerk: ";
	cin >> myDrive;

	cout << endl << "Ordner: ";
	cin >> myFolder;

	cout << endl << "Dateiname: ";
	cin >> myFile;

	cout << endl << "Text/Inhalt: ";
	cin >> myText;

	if (myDrive == "0" && myFolder == "0") {
		writeFile(0, 1, "", "", myFile, myText);
	}
	else if (myDrive == "0") {
		writeFile(0, 1, "", myFolder, myFile, myText);
	}
	else if (myFolder == "0") {
		writeFile(0, 1, myDrive, "", myFile, myText);
	}
	else {
		writeFile(0, 1, myDrive, myFolder, myFile, myText);
	}



	// Datei auslesen
	cout << endl << "Nun ist es an der Zeit, eine Datei auszulesen!";

	cout << endl << "Laufwerk: ";
	cin >> myDrive;

	cout << endl << "Ordner: ";
	cin >> myFolder;

	cout << endl << "Dateiname: ";
	cin >> myFile;

	if (myDrive == "0" && myFolder == "0") {
		readFile(1, "", "", myFile);
	}
	else if (myDrive == "0") {
		readFile(1, "", myFolder, myFile);
	}
	else if (myFolder == "0") {
		readFile(1, myDrive, "", myFile);
	}
	else {
		readFile(1, myDrive, myFolder, myFile);
	}
}