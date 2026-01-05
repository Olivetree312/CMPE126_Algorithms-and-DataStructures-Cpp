/*
 * Passenger.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#include "Passenger.h"

using namespace std;

Passenger::Passenger(): first_name("John"), last_name("Doe"),
	fare_discount(0.0){}
//copy constructors don't worry about self-assignment
Passenger::Passenger(const Passenger& p){
	first_name = p.getFirst_name();
	last_name = p.getLast_name();
	dateOfBirth = p.getDateOfBirth();
	fare_discount = p.getFareDiscount();
}
Passenger::Passenger(string first, string last, const DateOfBirth& dob){
	first_name = first;
	last_name = last;
	dateOfBirth = dob;
	fare_discount = 0.0;
}

string Passenger::getFirst_name() const{return first_name;}
string Passenger::getLast_name() const{return last_name;}
DateOfBirth Passenger::getDateOfBirth() const{return dateOfBirth;}
double Passenger::getFareDiscount() const{return fare_discount;}
void Passenger::setFirst_name(string first){first_name = first;}
void Passenger::setLast_name(string last){last_name = last;}
void Passenger::setDateOfBirth(DateOfBirth& date){dateOfBirth = date;}
void Passenger::setFareDiscount(double fare){fare_discount = fare;}

ostream& operator<<(ostream& out, Passenger& p){
	out << "Name: " << p.first_name << " " << p.last_name << endl;
	out << "Date of Birth: " << p.dateOfBirth;
	out << "Fare Discount: " << p.fare_discount << "%" << endl;
	return out;
}



