/*
 * arrayList.cpp
 *
 *  Created on: Feb 18, 2025
 *      Author: oliviachen
 */
#include "arrayList.h"
//exception handling
#include <exception>
#include <typeinfo>
#include <string>

using namespace std;

//EVERY MEMBER FUNCTION NEEDS TO EXPLICITLY MENTION TEMPLATE PARAM
//*************arrayList<T,N>
template <class T, size_t N>
//default size 10

arrayList<T,N>::arrayList(){
	arr = new T[N];
	currSize = 0;
	maxSize = 0;
	type = typeid(T).name();
}
//need parameter for type & size
//allows for array of any type/ size to be parameterized
//NEEDED FOR EVERY INSTANCE OF TEMPLATE
template <class T, size_t N>
//size_t N cannot be used as both name of non-type template param
//	& param name in constructor
arrayList<T,N>::arrayList(size_t maxSize){
	arr = new T[N];
	currSize = 0;
	this->maxSize = maxSize;
	type = typeid(T).name();
}

//copy constructor
template <class T, size_t N>
arrayList<T,N>::arrayList(const arrayList<T,N> &other){
	if(this!=&other){
		arr = new T[N];
		currSize = other.currSize;
		maxSize = other.maxSize;
		type = other.type;
		for(int i=0; i<currSize; i++){
			arr[i] = other.arr[i];
		}
	}
}
//virtual destructor ensures when base class ptr used
//	to delete class obj --> correct destructor of derived called
//free dynamically allocated memory
//ARRAY OF POINTERS NEEDS TO BE ITERATED THROUGH, but not normal arr
template <class T, size_t N>
arrayList<T,N>::~arrayList(){
	delete[] arr;
	cout << "destructor called" << endl;
}

template<class T, size_t N>
void arrayList<T,N>::setMaxSize(size_t maxSize){
	if(maxSize>=0)
		this->maxSize = maxSize;
	else{
		throw invalid_argument("Invalid upper limit (cannot be negative)");
	}
}

template <class T, size_t N>
//array of bool is empty if all false
//array of string is empty if all elements empty
//array of numbers empty if all elements zero
bool arrayList<T,N>::isEmpty() const{
	return currSize==0;
}

template <class T, size_t N>
//array of bool is full if all true
//array of string is full if none of elements empty
//array of numbers full if none of elements zero
bool arrayList<T,N>::isFull() const{
	return currSize==N;
}
template <class T, size_t N>
//returns current size of list
int arrayList<T,N>::listSize() const{
	return currSize;
}
template <class T, size_t N>
//returns user set max size OR zero if uninitialized
int arrayList<T,N>::maxListSize() const{
	if(maxSize==0)
		cout << "Upper limit not set" << endl;
	return maxSize;
}
template <class T, size_t N>
void arrayList<T,N>::print(){
	cout << "printing array:" << endl;
	if(arr!=nullptr){
		for(int i=0; i<currSize; i++){
			cout << i << ". " << arr[i] << endl;
		}
	}
	else
		cout << "null array" << endl;
}
template <class T, size_t N>
bool arrayList<T,N>::isItemAtEqual(int index, T element){
	//check if index <= currSize
	if(!(index<currSize)||index<0){
		throw out_of_range("Index out of bounds");
	}
	if(arr[index]==element)
		return true;
	else
		return false;
}
template <class T, size_t N>
//allows expansion of array size
//assigns new arr if currSize < index
void arrayList<T,N>::insertAt(int index, T element){
	T* temp;
	if(index<0)
		throw domain_error("Invalid index");
	//creating new arr if index greater
	if(index>currSize){
		currSize = index+1;
		temp = new T[currSize]();
	}
	else{
		currSize++;
		temp = new T[currSize]();
	}
	//temp copy just before insertion
	for(int i=0; i<index; i++){
		temp[i] = arr[i];
	}
	//temp insert
	temp[index] = element;
	//temp copy after insertion
	for(int i=index+1; i< currSize; i++){
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
template <class T, size_t N>
void arrayList<T,N>::insertEnd(T element){
	currSize+=1;
	T* temp = new T[currSize];
	//temp copy just before insertion
	for(int i=0; i<currSize-1; i++){
		temp[i] = arr[i];
	}
	//temp insert
	temp[currSize-1] = element;
	delete[] arr;
	arr = temp;
}
template <class T, size_t N>
void arrayList<T,N>::removeAt(int index){
	if(index<0||index>currSize)
		throw domain_error("Invalid index");
	currSize--;
	T* temp = new T[currSize];
	//temp copy just before deletion
	for(int i=0; i<currSize+1; i++){
		if(i==index)
			continue;
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
template <class T, size_t N>
T arrayList<T,N>::retrieveAt (int index){
	if(index<0||index>currSize-1)
		throw domain_error("Invalid index");
	else
		return arr[index];
}
template <class T, size_t N>
void arrayList<T,N>::replaceAt(int index, T element){
	if(index<0||index>currSize-1)
		throw domain_error("Invalid index");
	else
		arr[index] = element;
}
template <class T, size_t N>
void arrayList<T,N>::clearList(){
	T* temp = new T[currSize]();
	delete[] arr;
	arr = temp;
}

template <class T, size_t N>
arrayList<T,N>& arrayList<T,N>::operator=(const arrayList<T,N>& arr){
	if(this!=&arr){
		this->currSize = arr.currSize;
		this->maxSize = arr.maxSize;
		this->type = arr.type;
		delete[] this->arr;
		this->arr = new T[currSize];
		//deep copy from source arr
		for(int i=0; i<this->currSize; i++){
			this->arr[i] = arr.arr[i];
		}
	}
	return *this;
}

//explicit template instantiation needed for separate compilation
template class arrayList<int,10>;
template class arrayList<string, 10>;






