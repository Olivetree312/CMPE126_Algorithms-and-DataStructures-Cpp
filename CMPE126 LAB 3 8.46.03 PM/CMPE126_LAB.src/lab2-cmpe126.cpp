#include <iostream>
#include "DateOfBirth.h"
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Time.h"
#include <string>

using namespace std;

int main(){
//TESTING Date & DateOfBirth
	Date d1; //d1 initialized to January 1st, 1900
	Date d2 (3, 15, 2024); //d2 initialized to March 15th, 2024s
	DateOfBirth d3 (5, 10, 1970); //d3 initialized to May 10th, 1970
	DateOfBirth d4(d1); //d4 initialized to January 1st, 1900, copying from d1
	cout << d1;
	cout << d3 << d4;
	cout << d3.getAge() << endl;
	//You can make today’s date a global or static variable
	//	->obtained today's date using chrono header functions
//TESTING Passenger
	//curly quotes used in instructions --> changed to straight quotes
	string first_name = "John";
	string last_name = "Smith";
	DateOfBirth d(5, 10, 1970);
	Passenger p1(first_name, last_name, d);
	cout << p1; //Outputs flight information in a suitable format
	p1.setFareDiscount(0.25); //Sets the fare_discount meeting to 0.25, i.e., 25%
//TESTING Time
	Time t1; //t1 initialized to 0 hour 0 minute, i.e., 12:00
	Time t2 (3); //t2 initialized to 3 hour 0 minute, i.e., 03:00
	Time t3 (5,10); //t3 initialized to 5 hour 10 minute, i.e., 05:10
	cout << t1;
	cout << t2 << t3;
//TESTING Flight
	string src = "SFO";
	string dest = "LAX";
	Flight f1(src, dest); //Note that there should be no default value of src and dest
	f1.setDepartureTime(13, 45); //Sets the departureTime field to 13:45
	cout << f1; //Outputs flight information in a suitable format
	Time t(6, 30);
	f1.setDepartureTime(t);
	cout << f1;
	f1.setBaseFare(235.85);
//TESTING Ticket
	Ticket ticket(p1, f1);
	//In f1, update 235.85 as the base fare and d2 as dateOfTravel
	cout << ticket << endl; //Outputs flight information in a suitable format
	p1.setFareDiscount(0.5); //Update fare discount to 0.5, i.e., 50%
	ticket.updateFare(); //Updates the fare based on passenger discount
	cout << ticket.getFare(); //Outputs flight information in a suitable format
	Date d5(3, 18, 2024);
	Flight f2("SFO", "LAS", d5);
	ticket.updateFlight(f2); //Updates flight information
}
