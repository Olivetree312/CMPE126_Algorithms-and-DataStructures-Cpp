#include "HashTableChaining.h"
#include <iostream>
#include <iomanip>

using namespace std;

HashTableChaining::HashTableChaining(){
	HTSize = 10;
	//NEED TO CREATE DYNAMIC ARRAY WITH SIZE FIRST
	nodeArr = new Node*[10];
	for(int i=0; i<HTSize; i++){
		nodeArr[i] = nullptr;
	}
}
HashTableChaining::HashTableChaining(int size){
	HTSize = size;
	nodeArr = new Node*[HTSize];
	for(int i=0; i<HTSize; i++){
		nodeArr[i] = nullptr;
	}
}

void HashTableChaining::print(){
	cout << "INDEX" << setw(3) << " "<< setw(10) << " KEY/ VALUE " << endl;
	Node *ptr;
	for(int i=0; i<HTSize; i++){
		ptr = nodeArr[i];
		cout <<setw(3) << i << ": ";
		if(ptr==nullptr){
			cout << "null";
		}
		while(ptr!=nullptr){
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}
//uses chaining -> NO OVERFLOW, so always TRUE
bool HashTableChaining::insert(int val){
	int index = val%HTSize;
	Node* elem = new Node(val);
	Node* temp = nodeArr[index];
	//if head is null
	if(nodeArr[index]==nullptr){
		nodeArr[index] = elem;
		return true;
	}
	//while ptr to NEXT NODE != null, not ptr itself null
	while(temp->next!=nullptr){
		temp = temp->next;
	}
	//traversed to end of linked list at array index
	//link elem to end of linked list
	temp->next = elem;
	return true;
}
int HashTableChaining::search(int key){
	Node* ptr;
	for(int i=0; i<HTSize; i++){
		ptr = nodeArr[i];
		while(ptr!=nullptr){
			if(ptr->data==key){
				return i;
			}
			ptr = ptr->next;
		}
	}
	return -1;
}
//VIRTUAL destructor needed
//deleting DYNAMIC ARRAY of LINKED LISTS
HashTableChaining::~HashTableChaining(){
	Node* ptr;
	for(int i=0; i<HTSize; i++){
		ptr = nodeArr[i];
		while(ptr!=nullptr){
			nodeArr[i] = nodeArr[i]->next;
			delete ptr;
		}
	}
	delete[] nodeArr;
}




