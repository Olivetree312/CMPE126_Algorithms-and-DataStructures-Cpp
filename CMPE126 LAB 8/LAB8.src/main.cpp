#include <iostream>
#include "linkedList.h" //my own code from LAB 4
#include "arrayList.h" //my own code from LAB 3
#include "sortedArrayList.h"

using namespace std;

//code for LAB 8 member functions implemented in header files

int main(){
	//default arrayList maxSize is 10
	//creating arrays and lists to be searched
	//non-ordered array, contains descending ints 20 to 11
	arrayList<int,10> arr1;
	arr1.insertAt(0,20);
	arr1.insertAt(1,19);
	arr1.insertAt(2,18);
	arr1.insertAt(3,17);
	arr1.insertAt(4,16);
	arr1.insertAt(5,15);
	arr1.insertAt(6,14);
	arr1.insertAt(7,13);
	arr1.insertAt(8,12);
	arr1.insertAt(9,11);

	//ordered array, contains ascending ints 11 to 20
	arrayList<int,10> arr2;
	arr2.insertAt(0,11);
	arr2.insertAt(1,12);
	arr2.insertAt(2,13);
	arr2.insertAt(3,14);
	arr2.insertAt(4,15);
	arr2.insertAt(5,16);
	arr2.insertAt(6,17);
	arr2.insertAt(7,18);
	arr2.insertAt(8,19);
	arr2.insertAt(9,20);

	//singly linked list, descending ints 20 to 11
	Node<int>* head = new Node<int>(20);
	linkedList<int> list(head, 10);
	list.insertEnd(19);
	list.insertEnd(18);
	list.insertEnd(17);
	list.insertEnd(16);
	list.insertEnd(15);
	list.insertEnd(14);
	list.insertEnd(13);
	list.insertEnd(12);
	list.insertEnd(11);

	int elem, index;
	bool found;

	unsigned int choice = 0;
	do {
	cout << "Choose your search type:" << endl;
	cout << "1. Arrays: Sequential Search without recursion" << endl;
	cout << "2. Arrays: Sequential Search with recursion" << endl;
	cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
	cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
	cout << "5. Linked List: Search without recursion" << endl;
	cout << "6. Linked List: Search with recursion" << endl;
	cout << "Enter 0 to exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	cout<<"\nSpecify the element to be searched for: ";
	cin >> elem;
	if(choice==1){
		index = arr1.seqSearchIter(elem);
		cout << elem << " found at index: " << index << endl;
	}
	else if(choice==2){
		index = arr1.seqSearchRec(elem);
		cout << elem << " found at index: " << index << endl;
	}
	else if(choice==5){
		found = list.seqSearchIter(elem);
		cout << boolalpha<< elem << " found?: " << found << endl;
		}
	else if(choice==6){
		found = list.seqSearchRec(elem);
		cout << boolalpha<< elem << " found?: " << found << endl;
		}
	else{
		cout << "whoop invalid choice :((" << endl;
	}
	} while(choice!=0);

	//implementing sortedArrayList
	cout << "creating sortedArrayList..." << endl;
	sortedArrayList<int,10> arr3;
	arr3.insertAt(0,11);
	arr3.insertAt(1,12);
	arr3.insertAt(2,13);
	arr3.insertAt(3,14);
	arr3.insertAt(4,15);
	arr3.insertAt(5,16);
	arr3.insertAt(6,17);
	arr3.insertAt(7,18);
	arr3.insertAt(8,19);
	arr3.insertAt(9,20);
	arr3.print();

	return 0;
}


