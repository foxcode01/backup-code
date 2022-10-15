#include "Header.h"

#include <iomanip>
#include <ctime>

/**
 * @author foxcode01
 */

/*
// Disable warning messages 4996
#pragma warning( disable : 4996)
*/

// Issue warning C4996 only once
#pragma warning( once : 4996 )		// because localtime...

void getTime() {
	time_t now;
	struct tm nowLocal;

	now = time(NULL);				// get the time from the OS

	nowLocal = *localtime(&now);

	// Creating local variables for easier programming
	int day = nowLocal.tm_mday;
	int month = nowLocal.tm_mon + 1;
	int year = nowLocal.tm_year + 1900;
	int hour = nowLocal.tm_hour;
	int minute = nowLocal.tm_min;
	int sec = nowLocal.tm_sec;

	// Creating the strings for a file
	string strDay = to_string(day);
	string strMonth = to_string(month);
	string strYear = to_string(year);
	string strHour = to_string(hour);
	string strMinute = to_string(minute);
	string strSec = to_string(sec);

	if (day < 10) {
		strDay = "0" + strDay;
	}
	if (month < 10) {
		strMonth = "0" + strMonth;
	}
	if (hour < 10) {
		strHour = "0" + strHour;
	}
	if (minute < 10) {
		strMinute = "0" + strMinute;
	}
	if (sec < 10) {
		strSec = "0" + strSec;
	}

	string myDate = strYear + strMonth + strDay;
	string myTime = strHour + strMinute + strSec;

	// from here the transfer of the information of the date and time begins 
	timeInfFile(myDate, myTime, strYear, strMonth, strDay, strHour, strMinute, strSec);
	timeInLog(myDate, myTime, strYear, strMonth, strDay, strHour, strMinute, strSec);
}