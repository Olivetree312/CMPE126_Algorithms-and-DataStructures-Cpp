/*
 * DateOfBirth.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#include <iostream>
#include <chrono> //gives current time
#include "DateOfBirth.h"

using namespace std;

Date:: Date(): month(1), day(1), year(1990){}
Date:: Date(int month, int day, int year): month(month),
		day(day), year(year){}
Date:: Date(const Date& d){
	day = d.day;
	month = d.month;
	year = d.year;
}

//getters & setters
int Date::getDay() const{return day;}
int Date::getMonth() const{return month;}
int Date::getYear() const{return year;}
void Date::setDay(int day){
	if(isValidDay(day))
		this->day = day;
	else{
		cout << "Invalid date." << endl;
	}
}
void Date::setMonth(int month){
	if(isValidMonth(month))
		this->month = month;
	else
		cout << "Invalid month." << endl;
}
void Date::setYear(int year){
	if(isValidYear(year))
		this->year = year;
	else
		cout << "Invalid year" << endl;
}

bool Date::isValidDay(int day) const{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>=1&&day<=31)
			return true;
	}
	if(month==2){ //not including leap day because it's dumb
		if(day>=1&&day<=28)
			return true;
	}
	if(month==4||month==6||month==9||month==11){
		if(day>=1&&day<=30)
			return true;
	}
	return false;
}
bool Date:: isValidMonth(int month) const{
	if(month>=1&&month<=12)
		return true;
	else
		return false;
}
bool Date::isValidYear(int year){
	int temp = year;
	int digit = 0;
	while(temp!=0){
		temp/=10;
		digit++;
	}
	if(digit!=4)
		return false;
	else
		return true;
}

ostream& operator<<(ostream& out, Date& d){
	out << d.month << "/" << d.day << "/" << d.year << endl;
	return out;
}
istream& operator>>(istream& in, Date& d){
	int mm, dd, yyyy;
	cout << "Enter month, day, year: (space between each)";
	while(true){
		in >> mm >> dd >> yyyy;
		if(d.isValidMonth(mm)&&d.isValidDay(dd)&&d.isValidYear(yyyy)){
			d.month = mm;
			d.day = dd;
			d.year = yyyy;
			break;
		}
		else
			cout << "Invalid date--try again." << endl;
	}
	return in;
}

DateOfBirth::DateOfBirth(): Date(){}
DateOfBirth::DateOfBirth(int month, int day, int year):
		Date(month, day, year){}
//ADDITIONAL copy constructor for parent class param
DateOfBirth::DateOfBirth(const Date& d): Date(d){}
DateOfBirth::DateOfBirth(const DateOfBirth& d): Date(d){}

//use chrono header
int DateOfBirth:: getAge() const{
	//gets time point/ internal clock format (not human readable)
	auto now = chrono::system_clock::now();
	//time point->time_t value (integer = seconds since epoch)
	time_t now_c = chrono::system_clock::to_time_t(now);
	//tm struct contains separate fields for year, month, day, hour, min
	//tm struct is human-readable
	//*localtime is dereferenced point so var now stores copy of tm struct
	tm localTime = *localtime(&now_c);

	//tm_year gives yrs since 1900
	int currYear = localTime.tm_year + 1900;
	return currYear - year;
}

//date of birth must be from 1900 - 2024
bool DateOfBirth:: isValidYear(int year){
		return (year>1900&&year<2024);
	}

