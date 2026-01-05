/*
 * Weight.h
 *
 *  Created on: Mar 11, 2025
 *      Author: oliviachen
 */

#ifndef WEIGHT_H_
#define WEIGHT_H_

#include <iostream>
#include <stdexcept>

using namespace std;

class Weight{
public:
	Weight();
	Weight(int pounds, int ounces);
	Weight(const Weight &w);
	int getPounds();
	int getOunces();
	void setPounds(int num);
	void setOunces(int num);
	friend ostream& operator<<(ostream& out, Weight& w);

	bool operator<=(Weight &other);
	bool operator>=(Weight &other);

	Weight operator+(Weight& a);
protected:
	int pounds, ounces;
	bool validPounds(int num);
	bool validOunces(int num);
};

#endif /* WEIGHT_H_ */
