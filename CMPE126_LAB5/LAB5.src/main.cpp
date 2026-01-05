#include "linkedList.h"
#include "arrayList.h"
#include <iostream>

using namespace std;

//FUNCTION DECLARATIONS FOR CPP FILE FUNC WO HEADERS
unsigned int perrin(const unsigned int &n);
unsigned int set_bit_count(const int &n);

int main(){
	//using cout in perrin function because
	//eclipse debugger not working on mac :'((
	perrin(7);
	int bits = set_bit_count(123);
	cout << "total bits: " << bits << endl;

	//testing linkedList
	linkedList<int> list;
	list.insertAt(0,5);
	list.insertAt(1,10);
	list.insertAt(2,1);
	list.insertAt(3,70);
	list.insertAt(4,4);

	Node<int>* ptr = list.getHead();
	int max = list.retrieveAt(0);
	list.getMaxRecursive(ptr, max);
}





