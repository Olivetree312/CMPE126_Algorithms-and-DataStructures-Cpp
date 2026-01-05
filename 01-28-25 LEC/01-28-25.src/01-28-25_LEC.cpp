/*
 * 01-28-25_LEC.cpp
 *
 *  Created on: Jan 28, 2025
 *      Author: oliviachen
 */

#include <iostream>
#include <cmath>
using namespace std;

class Vector2D{
public:
	double getMagnitude();
	double getMagnitude(int x, int y);
	Vector2D(): x(0), y(0){}
	Vector2D(int x, int y): x(x), y(y){}
private:
	int x;
	int y;

};

//returnType className :: methodName(){}
double Vector2D :: getMagnitude(){
	double magnitude = sqrt(x*x + y*y);
	return magnitude;
}

double Vector2D :: getMagnitude(int x, int y){
	this->x = x;
	this->y = y;
	return getMagnitude();
}

int main(){
	int x, y;
	x = 5;
	y = 6;
	Vector2D v1(x,y);
	double d = v1.getMagnitude();
	cout << d << endl;
}



