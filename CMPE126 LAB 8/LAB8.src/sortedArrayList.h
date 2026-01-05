/*
 * sortedArrayList.h
 *
 *  Created on: Apr 17, 2025
 *      Author: oliviachen
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include "arrayList.h"

using namespace std;

template <class T, size_t N>
class sortedArrayList : public arrayList<T,N>{
public:
	sortedArrayList(): arrayList<T,N>(){}
	sortedArrayList(size_t maxSize): arrayList<T,N>(maxSize){}
	//copy constructor
	//***templated classes need this-> to access protected base members
	sortedArrayList(const sortedArrayList<T,N> &other){
		if(this!=&other){
			this->arr = new T[N];
			this->currSize = other.currSize;
			this->maxSize = other.maxSize;
			this->type = other.type;
			for(int i=0; i<this->currSize; i++){
				this->arr[i] = other.arr[i];
			}
		}
	}

	//isEmpty() same as arrayList
	//isFull() same as arrayList
	//listSize() same as arrayList
	//maxListSize() same as arrayList
	//print() same as arrayList
	//remove() same as arrayList
	//clearList() same as arrayList
	//base class has virtual destructor

	//ONLY difference is insert -> user not allowed to choose index
	void insert(T elem){
		int count=0;
		if(this->isFull()){
			throw domain_error("List full");
		}
		if(this->isEmpty()){
			this->arr[0] = elem;
		}
		else{
			while(elem<this->arr[++count]){}
			this->arr[count-1] = elem;
		}
	}
};

template class sortedArrayList<int,10>;

#endif /* SORTEDARRAYLIST_H_ */
