/*
 * Ticket.cpp
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */
#include "Ticket.h"
#include <iomanip> //needed for setprecision

using namespace std;

Ticket::Ticket(): passenger(), flight(), passengerFare(flight.getBaseFare()){}
Ticket::Ticket(Passenger p, Flight f): passenger(p), flight(f),
		passengerFare(flight.getBaseFare()){}
Ticket::Ticket(Passenger p, Flight f, double fare): passenger(p),
		flight(f), passengerFare(fare){}

Passenger Ticket::getPassenger() const{return passenger;}
Flight Ticket::getFlight() const{return flight;}
double Ticket::getFare() const{return passengerFare;}
void Ticket::setPassenger(Passenger p){passenger = p;}
void Ticket::setFlight(Flight f){flight = f;}
void Ticket::setFare(double fare){passengerFare = fare;}
void Ticket::updateFare(){
	passengerFare -= (passenger.getFareDiscount()*passengerFare);
}
void Ticket::updateFlight(Flight f){
	flight = f;
}
ostream& operator <<(ostream& out, Ticket& t){
	out << t.passenger;
	out << t.flight;
	out << "Passenger fare: $" << fixed << setprecision(2) << t.passengerFare << endl;
	return out;
}

