/*
 * Passenger.h
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
#include <string>
#include "DateOfBirth.h"

using namespace std;

class Passenger: public DateOfBirth{
public:
	Passenger();
	Passenger(const Passenger& p);
	Passenger(string first, string last, const DateOfBirth& dob);

	string getFirst_name() const;
	string getLast_name() const;
	DateOfBirth getDateOfBirth() const;
	double getFareDiscount() const;
	void setFirst_name(string first);
	void setLast_name(string last);
	void setDateOfBirth(DateOfBirth& date);
	void setFareDiscount(double discount);

	friend ostream& operator<<(ostream& out, Passenger& p);
	friend istream& operator>>(istream& in, Passenger& p);

private:
	string first_name, last_name;
	DateOfBirth dateOfBirth;
	double fare_discount;
};




#endif /* PASSENGER_H_ */
