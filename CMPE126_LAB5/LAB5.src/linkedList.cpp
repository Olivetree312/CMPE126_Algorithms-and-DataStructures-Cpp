#include "linkedList.h"
#include <iostream>
//enables sorting
#include <algorithm>

using namespace std;

//Node constructor w curr val, null nextVal
template <class T> Node<T>::Node(T data): data(data), next(nullptr){}

template <class T> linkedList<T>::linkedList(Node<T>* head, int maxSize): head(head), maxSize(maxSize){
	size = listSize();
}

//default maxSize of 10
template <class T> linkedList<T>::linkedList(): head(nullptr), maxSize(10), size(0){}

template <class T> void linkedList<T>::insertEnd(T elemType){
	insertAt(size, elemType);
}
//getters
template <class T> Node<T>* linkedList<T>::getHead() const{return head;}
//setters
template <class T> void linkedList<T>::setHead(Node<T>* head){
	delete this->head;
	this->head = head;
}

template <class T> bool linkedList<T>::isEmpty() const{
	return(head==nullptr);
}
template <class T> bool linkedList<T>::isFull() const{
	return (size==maxSize);
}
template <class T> bool linkedList<T>::isItemInList(T elemType){
	for(int i=0; i<size; i++){
		if(retrieveAt(i)==elemType)
			return true;
	}
	return false;
}
//traverses linkedList to find current size
template <class T> int linkedList<T>::listSize() const{
	Node<T>* curr = head;
	int count = 0;
	while(curr!=nullptr){
		curr = curr->next; //moves to Node's ptr to next Node
		count++;
	}
	return count;
}
template <class T> int linkedList<T>::maxListSize() const{return maxSize;}

template <class T> void linkedList<T>::print(){
	Node<T>* curr = head;
	cout << "size: " << size << endl;
	while(curr!=nullptr){
		cout << curr->data << endl;
		curr = curr->next;
	}
}
template <class T> bool linkedList<T>::isItemAtEqual(int index, T elemType){
	if(index>=size||index<0){
		cerr << "Index out of bounds" << endl;
		return false;
	}
	T itemAt = retrieveAt(index);
	if(elemType==itemAt)
		return true;
	else
		return false;
}
//obj at index will be moved after
//inserting at end allowed
template <class T> void linkedList<T>::insertAt(int index, T elemType){
	if(index>size+1||index<0){
		cerr << "Index out of bounds" << endl;
		return;
	}
	if(size==maxSize){
		cerr << "Max size reached" << endl;
		return;
	}
	//make new Node ptr containing curr elemType
	Node<T>* newNode= new Node<T>(elemType);
	//save ptr to Node at index, to be moved after insertion
	Node<T>* afterNode, * beforeNode;

	//if inserting at end
	if(index==size&&index!=0){
		beforeNode = retrieveNodePtrAt(index-1);
		beforeNode->next = newNode;
	}
	//if inserting at beg
	else if(index==0){
		newNode->next = head;
		head = newNode;
	}
	else{
		beforeNode = retrieveNodePtrAt(index-1);
		afterNode = retrieveNodePtrAt(index);
		beforeNode->next = newNode;
		newNode->next = afterNode;
	}
	//newNode memory being used, no need for delete
	size++;

}
template <class T> void linkedList<T>::removeAt(int index){
	if(index>=size||index<0){
		cerr << "Index out of bounds" << endl;
		return;
	}
	Node<T>* currNode = retrieveNodePtrAt(index);
	Node<T>* afterNode, * beforeNode;
	//if removing from end
	if(index==size-1){
		beforeNode = retrieveNodePtrAt(index-1);
		beforeNode->next = nullptr;
	}
	//if removing from beg
	else if(index==0){
		afterNode = retrieveNodePtrAt(index+1);
		head = afterNode;
	}
	else{
		beforeNode = retrieveNodePtrAt(index-1);
		afterNode = retrieveNodePtrAt(index+1);
		beforeNode->next = afterNode;
	}
	delete currNode;
	//newNode memory being used, no need for delete
	size--;
}
//returns head Node's T if index OOB
template <class T> Node<T>* linkedList<T>::retrieveNodePtrAt(int index) const{
	if(index>size-1){ //size-1=maxIndex
		cerr << "Index out of bounds" << endl;
		return head;
	}
	Node<T>* curr = head;
	int count=0;
	while(count<index){
		curr = curr->next;
		count++;
	}
	return curr;
}
template <class T> T linkedList<T>::retrieveAt(int index){
	Node<T>* obj= retrieveNodePtrAt(index);
	return obj->data;
}
template <class T> void linkedList<T>::replaceAt(int index, T elemType){
	Node<T>* curr = retrieveNodePtrAt(index);
	curr->data = elemType;
}
template <class T> void linkedList<T>::clearList(){
	Node<T>* curr = head;
	Node<T>* temp;
	while(curr!=nullptr){
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	//now head points to nullptr
	head=nullptr;
	size=0;
}

template <class T> linkedList<T>& linkedList<T>:: operator=(const linkedList<T>& other){
	if(this!=&other){
		clearList();
	}
	this->maxSize = other.maxSize;
	this->size = other.size;

	Node<T>*curr;

	//checking if list empty
	if(other.head ==nullptr){
		this->head = nullptr;
	}
	else{ //copying over first node
		this->head = new Node<T>(other.head->data);
		curr = this->head;
		Node<T>* otherCurr = other.head->next;

	while(otherCurr!=nullptr){
		curr->next = new Node<T>(otherCurr->data);
		curr = curr->next;
		otherCurr = otherCurr->next;
		}
	}
	return *this;
}

template <class T> linkedList<T>::~linkedList(){
	clearList();
}

//sorry im not sure how i can impliment this function
//without using any arguments
template <class T> T linkedList<T>::getMaxRecursive(Node<T>* curr, T max){
	//base condition: end is reached
	if(curr==nullptr){
		cout << "end of linked list reached --> returning max" << endl;
		return max;
	}
	if(curr->data>max){
		cout << "value of next node is greater--> changing max" << endl;
		max = curr->data;
	}
	T ans = getMaxRecursive(curr->next, max);
	cout << "returning max = " << ans << endl;
	return ans;
}

//for template function declaration to be written outside header -> explicit template instantiation
template class linkedList<int>;
template class linkedList<double>;
template class linkedList<bool>;
template class linkedList<float>;




