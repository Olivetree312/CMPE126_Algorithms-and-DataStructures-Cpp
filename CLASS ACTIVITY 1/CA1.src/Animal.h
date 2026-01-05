/*
 * Animal.h
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
using namespace std;

class Animal{
public:
	Animal();
	Animal(const string& name, int age);
	// Getter for name
	string getName() const;
	// Setter for name
	void setName(const string& name);
	// Getter for age
	int getAge() const;
	// Setter for age
	void setAge(int age);
	// Virtual func makeSound()
	// Virtual fuctions ensure dervied class function called,
	//even when accessed via base class ptr
	virtual void makeSound() const;

	//overloaded operator = friend
	friend ostream& operator <<(ostream& cout, Animal& a);
	friend istream& operator >>(istream& cin, Animal& a);
	Animal& operator=(const Animal& a);
	virtual ~Animal();

private:
	string name;
	int age;
};

#endif /* ANIMAL_H_ */
