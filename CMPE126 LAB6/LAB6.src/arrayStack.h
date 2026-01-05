/*
 * arrayStack.h
 *
 *  Created on: Mar 19, 2025
 *      Author: oliviachen
 */
#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <string>
#include <iostream>

using namespace std;

class arrayStack{
public:
	arrayStack(int size): arr(new string[size]), maxSize(size), topIndex(-1){}
	//using dynamic mem allo so need destructor
	~arrayStack(){delete[] arr;}

	void push(const string& value){
		//if topIndex is equal to capacity index -> no pushing!
		if(topIndex == maxSize-1){
			cout << "Stack overflow" << endl;
			return;
		}
		//increment topIndex, then set equal to value
		arr[++topIndex] = value;
	}
	void pop(){
		if(isEmpty())
			cout << "Stack is empty" << endl;
		//reset topIndex to empty string & decrement topIndex
		arr[topIndex--] = "";
	}
	string top(){
		if(isEmpty()){
			cout << "Stack is empty" << endl;
			return "";
		}
		return arr[topIndex];
	}
	bool isEmpty(){
		return topIndex == -1;
	}
	int size(){
		return topIndex + 1;
	}
private:
	string* arr;
	int maxSize, topIndex;
};

#endif /* ARRAYSTACK_H_ */
