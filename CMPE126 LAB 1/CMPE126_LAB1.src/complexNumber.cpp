/*
 * complexNumber.cpp
 *
 *  Created on: Feb 4, 2025
 *      Author: oliviachen
 */
#include <iostream>
#include "complexNumber.h"
#include <cctype>

using namespace std;

//returnType Class::funcName()
complexNumber::complexNumber(): a(0),b(0){}
complexNumber::complexNumber(int a): a(a), b(0){}
complexNumber::complexNumber(int a, int b): a(a), b(b){}

//getters & setters, OR use friend functions
void complexNumber::setA(int a){this->a = a;}
void complexNumber::setB(int b){this->b = b;}
int complexNumber::getA() const{return a;}
int complexNumber::getB() const{return b;}

//not friend func, so must use getters
complexNumber complexNumber::operator+(complexNumber const& num){
	int real = a+num.getA();
	int imag = b+num.getB();
	return complexNumber(real, imag);
}
complexNumber complexNumber::operator-(complexNumber const& num){
	int real = a-num.getA();
	int imag = b-num.getB();
	return complexNumber(real, imag);
}
complexNumber complexNumber::operator*(complexNumber const& num){
	int real = a*num.getA();
	int imag = b*num.getB();
	return complexNumber(real, imag);
}

//friend functions, but friend keyword used in header file
//FRIEND FUNC can access private members of class -> don't need getters
//BE CONSISTENT WITH CONST KEYWORD IN FUNC SIGNATURES
	//-->MUST MATCH HEADER FILE
ostream& operator <<(ostream& cout, const complexNumber& num){
	//saving current flags in cout stream
	ios_base::fmtflags f = cout.flags();

	//SHOWPOS FORCES + sign for imaginary component
	cout << num.a << showpos << num.b << "i" << endl;

	//resetting showpos, restoring previosu flags
	cout.flags(f);

	return cout;
}
//INPUT VALIDATION
istream& operator >>(istream& cin, complexNumber& num){
	while(true){
		cout << "Enter real component 'a': ";
		cin >> num.a;
		//ERROR CHECKING
		if(cin.fail()){
			cin.clear(); //clears error flag
			//IGNORES all invalid input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input." << endl;
		}
		else
			break;
	}
	while(true){
			cout << "Enter imaginary component 'b': ";
			cin >> num.b;
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input." << endl;
			}
			else
				break;
		}
	return cin;
}




