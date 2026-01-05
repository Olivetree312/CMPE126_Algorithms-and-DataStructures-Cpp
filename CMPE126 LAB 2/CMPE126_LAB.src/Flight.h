/*
 * Flight.h
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>
#include "Time.h"
#include "DateOfBirth.h"
#include <string>

using namespace std;

class Flight{
public:
	Flight();
	Flight(string src, string dest, Time& departureTime);
	Flight(string src, string dest);
	Flight(string src, string dest, Date& dateOfTravel);

	string getSrc() const;
	string getDest() const;
	Time getDepartureTime() const;
	double getBaseFare() const;
	Date getDateOfTravel() const;
	void setSrc(string src);
	void setDest(string dest);
	void setDepartureTime(Time t);
	void setDepartureTime(int hour, int minute);
	void setBaseFare(double fare);
	void setDateOfTravel(Date d);
	void setDateOfTravel(int month, int day, int year);

	Flight& operator=(const Flight& f);
	friend ostream& operator <<(ostream& out, Flight f);

private:
	string src, dest;
	Time departureTime;
	double baseFare;
	Date dateOfTravel;
};


#endif /* FLIGHT_H_ */
