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
	arrayList();
	arrayList(size_t maxSize);
	//copy constructor
	arrayList(const arrayList<T,N> &other);

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
	//returns elem index if found, or arr size if NOT found
	unsigned int seqSearchIter(T elem){
		for(int i=0; i<currSize; i++){
			if(elem==arr[i]){return i;}
		}
		//current arr size returned if not found
		return currSize;
	}
//not sure how to do this with one parameter, so helper function used
	unsigned int seqSearchRec(T elem){
		return seqSearchRecHelper(elem, 0);
	}
	unsigned int seqSearchRecHelper(T elem, int index){
		if(index >= currSize-1){
			return currSize; //returns size if past last index
		}
		if(arr[index] == elem){
			return index;
		}
		//iterate to next index w recursive call
		return seqSearchRecHelper(elem, index+1);
	}

	arrayList& operator=(const arrayList& arr);

protected:
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

//needed for template support
#include "arrayList.tpp"

#endif /* ARRAYLIST_H_ */
