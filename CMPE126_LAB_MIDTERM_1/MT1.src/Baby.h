/*
 * Baby.h
 *
 *  Created on: Mar 11, 2025
 *      Author: oliviachen
 */

#ifndef BABY_H_
#define BABY_H_

#include <iostream>
#include "Weight.h"
#include "Dosage.h"
#include <string>

using namespace std;

class Baby{
public:
	Baby();
	//parameter with dose in case already known
	Baby(string name, Weight &weight, Dosage &dose);
	Baby(string name, Weight &weight, Dosage* doseList, int listLength);
	string getName();
	Weight getWeight();
	Dosage getDosage();

	void setName(string name);
	void setWeight(Weight &weight);
	void setDosage(Dosage &dose);

	friend ostream& operator<<(ostream& out, Baby &b);

protected:
	string name;
	Weight weight;
	Dosage dose;
};




#endif /* BABY_H_ */
