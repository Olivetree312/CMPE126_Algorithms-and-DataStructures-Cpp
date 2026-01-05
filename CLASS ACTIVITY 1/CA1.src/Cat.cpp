/*
 * Cat.cpp
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

#include "Cat.h"
#include <iostream>

using namespace std;

Cat::Cat(): Animal(), color("N/A"){}
Cat::Cat(const string& name, int age, const string& color):
	Animal(name, age), color(color){}

string Cat::getColor() const{
	return color;
}
void Cat::setColor(const string& color){
	this->color = color;
}
void Cat::makeSound() const{
	cout << "meow meow MEOW MEOW HISS" << endl;
}

ostream& operator <<(ostream& cout, Cat& a){
	cout << "Class Type: Cat" << endl;
	cout << "Name: " << a.getName() << endl;
	cout << "Age: " << a.getAge() << endl;
	cout << "Color: " << a.color << endl;
	return cout;
}

istream& operator >>(istream& cin, Cat& a){
	string temp;
	int i;
	cout << "Input name: ";
	cin >> temp;
	a.setName(temp);
	cout << "input age: ";
	cin >> i;
	a.setAge(i);
	cout << "\nInput color: ";
	cin >> temp;
	a.color = temp;
	return cin;
}

Cat& Cat::operator=(const Cat& a){
	if(this!=&a){
		setName(a.getName());
		setAge(a.getAge());
		color = a.getColor();
	}
	return *this;
}
