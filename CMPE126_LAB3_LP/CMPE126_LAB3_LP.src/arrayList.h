/*
 * arrayList.h
 *
 *  Created on: Feb 18, 2025
 *      Author: oliviachen
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
#include <string>
//exception handling
#include <exception>
#include <typeinfo>
#include <string>
//use typeid(var).name() --> returns string of variable
//typeid can even check type of uninitialized variables
#include <type_traits>

using namespace std;

//***FOR GENERIC ARRAY that can HANDLE DIFF SIZES WO
//****DYNAMIC MEM ALLOC --> N needs to be non-type template param (const values)
//N is compile time constant
template <class T, size_t N>
class arrayList{
public:
	//default size 10, type needed
	arrayList(string type);

	arrayList(string type, size_t size);
	//copy constructor
	arrayList(const arrayList &arr);
	//takes in ref to std::array of any type/size
	arrayList(const T arr[], size_t size);
	//virtual destructor ensures when base class ptr used
	//	to delete class obj --> correct destructor of derived called
	//free dynamically allocated memory
	virtual ~arrayList();

	void setMaxSize(size_t maxSize);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int index, T element);
	void insertAt(int index, T element);
	void insertEnd(T element);
	void removeAt(int index);
	T retrieveAt (int index);
	void replaceAt(int index, T element);
	void clearList();

	arrayList& operator=(const arrayList& arr);

private:
	//pointer to array
	//stack-allocated obj -> automatic destructor once out of scope
	//dynamically-allocated (heap) -> explicit delete needed
	//**POINTERS TO ARRAYS MUST ITERATE TO DELETE
	//EXPLICIT DELETE NEEDED in arrayList.cpp BUT ***>>
	//arrayList in main.cpp doesn't need explicit delete
	T* arr;
	//if maxSize=0 --> mention user hasn't set upper limit
	//maxSize must be explicitly set, does not equal current size
	size_t maxSize, currSize;
	string type;
	void makeTypeArr(string type, size_t size);
};

#endif /* ARRAYLIST_H_ */
