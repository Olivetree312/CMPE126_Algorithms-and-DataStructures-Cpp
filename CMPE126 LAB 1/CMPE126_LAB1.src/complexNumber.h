/*
 * complexNumber.h
 *
 *  Created on: Feb 4, 2025
 *      Author: oliviachen
 */

#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_

#include <iostream>

using namespace std;

class complexNumber{
public:
	//{} brackets used in class cpp file when initializing
	complexNumber();
	complexNumber(int a);
	complexNumber(int a, int b);

	//getters & setters, OR use friend func
	//friend allows for access of param private members
	void setA(int a);
	void setB(int b);
	int getA() const; //const goes AFTER FUNC SIGNATURE
					//& BEFORE PARAM TYPE
	int getB() const;


	complexNumber operator+(const complexNumber& num);
	complexNumber operator-(const complexNumber& num);
	complexNumber operator*(const complexNumber& num);
	friend ostream& operator <<(ostream& cout, const complexNumber& num);
	friend istream& operator >>(istream& cin, complexNumber& num);

private: //making members private is GOOD PRACTICE (albeit annoying)
		//allows for encapsulation, data mod control, security
	//LEGEND: a + bi, where a is real and b is imaginary
	int a, b;
};

#endif /* COMPLEXNUMBER_H_ */
