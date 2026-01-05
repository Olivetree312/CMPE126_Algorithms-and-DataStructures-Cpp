/*
 * Ticket.h
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#ifndef TICKET_H_
#define TICKET_H_

#include <iostream>
#include "Passenger.h"
#include "Flight.h"

using namespace std;

class Ticket{
public:
	Ticket();
	Ticket(Passenger p, Flight f);
	Ticket(Passenger p, Flight f, double fare);

	Passenger getPassenger() const;
	Flight getFlight() const;
	double getFare() const;
	void setPassenger(Passenger p);
	void setFlight(Flight f);
	void setFare(double fare);
	void updateFare();
	void updateFlight(Flight f);

	friend ostream& operator <<(ostream& out, Ticket& t);

private:
	Passenger passenger;
	Flight flight;
	double passengerFare;
};



#endif /* TICKET_H_ */
