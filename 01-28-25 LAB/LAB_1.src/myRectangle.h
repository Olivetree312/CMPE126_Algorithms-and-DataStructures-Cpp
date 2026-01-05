/*
 * myRectangle.h
 *
 *  Created on: Jan 28, 2025
 *      Author: oliviachen
 */

#include <iostream>
using namespace std;

#ifndef MYRECTANGLE_H_
#define MYRECTANGLE_H_
class myRectangle{
public:
	myRectangle(): width(0), length(0){}
	myRectangle(int w, int l): width(w), length(l){}
	void setWidth(int width){
		this->width = width;
	}
	void setLength(int length){
		this->length = length;
	}
	int getArea(){
		int area = width * length;
		return area;
	}
	void printArea(){
		cout << "area: " << getArea();
	}
private:
	int width, length;
};

#endif /* MYRECTANGLE_H_ */
