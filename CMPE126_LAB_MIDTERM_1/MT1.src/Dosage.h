/*
 * Dosage.h
 *
 *  Created on: Mar 11, 2025
 *      Author: oliviachen
 */

#ifndef DOSAGE_H_
#define DOSAGE_H_

#include <iostream>
#include "Weight.h"

using namespace std;

class Dosage{
public:
	Dosage();
	Dosage(Weight &min, Weight &max, double vol);
	friend ostream& operator<<(ostream& out, Dosage d);
	//comparison operator overload
	bool operator>(Dosage &other);
	bool operator<(Dosage &other);
	bool operator<=(Dosage &other);
	bool operator>=(Dosage &other);


	Weight minWeight, maxWeight;
	double volume; //in mL
};


#endif /* DOSAGE_H_ */
