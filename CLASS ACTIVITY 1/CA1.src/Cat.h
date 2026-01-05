/*
 * Cat.h
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>
#include "Animal.h"
using namespace std;

class Cat : public Animal{
public:
	Cat();
	Cat(const string& name, int age, const string& color);

	string getColor() const;
	void setColor(const string& color);
	void makeSound() const;
	friend ostream& operator <<(ostream& cout, Cat& a);
	friend istream& operator >>(istream& cin, Cat& a);
	Cat& operator=(const Cat& a);

private:
	string color;
};



#endif /* CAT_H_ */
