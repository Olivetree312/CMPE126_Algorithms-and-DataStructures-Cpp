/*
 * Flight.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#include "Flight.h"

using namespace std;

//blank for departureTime default time
Flight::Flight(): departureTime(), baseFare(0){}
Flight::Flight(string src, string dest): src(src), dest(dest), baseFare(0){}
Flight::Flight(string src, string dest, Time& departureTime):
	src(src), dest(dest), departureTime(departureTime),
	baseFare(0), dateOfTravel(){}
Flight::Flight(string src, string dest, Date& dateOfTravel): src(src),
		dest(dest), baseFare(0),dateOfTravel(dateOfTravel){}


string Flight::getSrc() const{return src;}
string Flight::getDest() const{return dest;}
Time Flight::getDepartureTime() const{return departureTime;}
void Flight::setSrc(string src){this->src = src;}
void Flight::setDest(string dest){this->dest = dest;}
void Flight::setDepartureTime(int hour, int minute){
	departureTime.setHour(hour);
	departureTime.setMinute(minute);
}
void Flight::setDepartureTime(Time t){this->departureTime = t;}

double Flight::getBaseFare() const{return baseFare;}
Date Flight::getDateOfTravel() const{return dateOfTravel;}

void Flight::setBaseFare(double fare){baseFare = fare;}
void Flight::setDateOfTravel(Date d){dateOfTravel = d;}
void Flight::setDateOfTravel(int month, int day, int year){
	dateOfTravel.setMonth(month);
	dateOfTravel.setDay(day);
	dateOfTravel.setYear(year);
}

Flight& Flight::operator=(const Flight& f){
	//avoid self assignment
	if(this==&f)
		return *this;
	else{
		src = f.getSrc();
		dest = f.getDest();
		departureTime = f.getDepartureTime();
		baseFare = f.getBaseFare();
		dateOfTravel = f.getDateOfTravel();
	}
	return *this;
}
ostream& operator <<(ostream& out, Flight f){
	out << "Flight from " << f.src << " to " << f.dest << endl;
	out << "Departure Time: " << f.departureTime.getHour()
			<< ":" << f.departureTime.getMinute() << endl;
	return out;
}


