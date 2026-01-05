/*
 * Dog.cpp
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

/*
 * Dog.h
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

//include base class's header file
#include <iostream>
#include "Dog.h"

using  namespace std;

Dog::Dog():Animal(), breed("N/A"){}
Dog::Dog(const string& name, int age, const string& breed):
		Animal(name, age), breed(breed){}

string Dog::getBreed() const{
	return breed;
}
void Dog::setBreed(const string& breed){
	this->breed  = breed;
}
void Dog::makeSound() const{
	cout << "arf RUFF RUFF grrrr bork bork" << endl;
}

ostream& operator <<(ostream& cout, Dog& a){
	cout << "Class Type: Dog" << endl;
	cout << "Name: " << a.getName() << endl;
	cout << "Age: " << a.getAge() << endl;
	cout << "Breed: " << a.breed << endl;
	return cout;
}

istream& operator >>(istream& cin, Dog& a){
	string s;
	int i;
	cout << "Input name: ";
	cin >> s;
	a.setName(s);
	cout << "\nInput age: ";
	cin >> i;
	a.setAge(i);
	cout << "\nInput breed: ";
	cin >> s;
	a.breed = s;
	return cin;
}

Dog& Dog::operator=(const Dog& a){
	if(this == &a)//if addresses same, return ref
		return *this; //this is pointer, *this is reference
	else{
		setName(a.getName());
		setAge(a.getAge());
		breed = a.getBreed();
	}
	return *this;
}






