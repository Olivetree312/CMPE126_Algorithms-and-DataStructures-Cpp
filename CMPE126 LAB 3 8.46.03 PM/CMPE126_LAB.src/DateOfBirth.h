/*
 * DateOfBirth.h
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

//SIMILAR CLASSES DECLARED IN SAME FILE
#ifndef DATEOFBIRTH_H_
#define DATEOFBIRTH_H_

#include <iostream>

using namespace std;

class Date{
public:
	Date();
	Date(int month, int day, int year);
	//copy constructor, doesn't need deep copy
	//	because only int is involved (copied by value, not ref)
	Date(const Date& d);

	//getters & setters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	//friend functions not inhertied, but derived class can still access
	//	bc derived classes still inherit private members
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);

	//base class destructor must be virtual
	virtual ~Date(){}

protected: //validate input in private
	int month, day, year;
	bool isValidDay(int day) const;
	bool isValidMonth(int month) const;
	virtual bool isValidYear(int year);

};

class DateOfBirth : public Date{
public:
	DateOfBirth();
	DateOfBirth(int month, int day, int year);
	//ADDITIONAL copy constructor for parent class param
	DateOfBirth(const Date& d);
	DateOfBirth(const DateOfBirth& d);

	int getAge() const;

protected:
	//date of birth must be from 1900 - 2024
	bool isValidYear(int year);
};

#endif /* DATEOFBIRTH_H_ */
