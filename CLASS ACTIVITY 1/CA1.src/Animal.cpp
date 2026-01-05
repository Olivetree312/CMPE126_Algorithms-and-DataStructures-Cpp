/*
 * Animal.cpp
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */
#include "Animal.h"
#include <iostream>
using namespace std;
// Implementations of Animal class methods
// Default constructor
Animal::Animal(): name("N/A"), age(0){}
// Parameterized constructor
Animal::Animal(const string& name, int age): name(name), age(age){}
// Getter for name
string Animal::getName() const {
	return name;
}
// Setter for name
void Animal::setName(const string& name) {
	this->name = name;
}
// Getter for age
int Animal::getAge() const {
	return age;
}
// Setter for age
void Animal::setAge(int age) {
	this->age = age;
}
// Virtual method makeSound()
void Animal::makeSound() const {
	cout << "RAWR" << endl;
}

//<< operator overload should return cout
ostream& operator <<(ostream& cout, Animal& a){
	cout << "Class Type: Animal" << endl;
	cout << "Name: " << a.name << endl;
	cout << "Age: " << a.age << endl;
	return cout;
}

//overloaded >> operator inputs animal input
//function overloading for each animal type
istream& operator >>(istream& cin, Animal& a){
	string s;
	int i;
	cout << "Input name: ";
	cin >> s;
	a.name = s;
	cout << "\nInput age: ";
	cin >> i;
	a.age = i;
	return cin;
}

Animal& Animal::operator=(const Animal& a){
	if(this!=&a){ //prevents self-assignment, checks if points to itself
		name = a.getName();
		age = a.getAge();
	}
	return *this; //dereferenced ptr is reference to obj
}

//virtual destructor
//include any time virtual func used
//virtual functions -> MOST DERIVED VER
//virtual DESTRUCTORS -> FROM DERIVED TO BASE
Animal::~Animal(){
	cout << "Animal virtual destructor called" << endl;
}



