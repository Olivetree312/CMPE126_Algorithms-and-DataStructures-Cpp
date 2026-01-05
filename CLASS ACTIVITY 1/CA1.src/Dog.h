/*
 * Dog.h
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

#ifndef DOG_H_
#define DOG_H_
//include base class's header file
#include <iostream>
#include "Animal.h"
using namespace std;

class Dog : public Animal{
public:
	Dog();
	Dog(const string& name, int age, const string& breed);

	string getBreed() const;
	void setBreed(const string& breed);
	void makeSound() const;
	friend ostream& operator <<(ostream& cout, Dog& a);
	friend istream& operator >>(istream& cin, Dog& a);
	Dog& operator=(const Dog& a);

private:
	string breed;
};



#endif /* DOG_H_ */
