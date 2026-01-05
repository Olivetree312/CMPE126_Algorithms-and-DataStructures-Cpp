/*
 * Time.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */
#include "Time.h"

using namespace std;

Time::Time(): hour(0), minute(0){}
Time::Time(int hour): hour(hour), minute(0){}
Time::Time(int hour, int minute): hour(hour), minute(minute){}

int Time::getHour() const{return hour;}
int Time::getMinute() const{return minute;}
void Time::setHour(int hour){
	if(isValidHour(hour)){
		this->hour = hour;
	}
	else
		cout << "Invalid hour." << endl;
}
void Time::setMinute(int minute){
	if(isValidMinute(minute)){
		this->minute = minute;
	}
	else
		cout << "Invalid minute." << endl;
}

ostream& operator <<(ostream& out, Time t){
	out << t.hour << " hours, " << t.minute << " minutes" << endl;
	return out;
}

bool Time::isValidHour(int hour){
	return (hour>=0&&hour<=23);
}
bool Time::isValidMinute(int minute){
	return (minute>=0&&minute<=59);
}



