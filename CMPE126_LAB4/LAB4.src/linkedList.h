/*INCLUDES NODE STRUCT
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

template <class T>
//struct is default public
struct Node{
	T data;
	Node* next;

	Node(T data);

};

template <class T>
class linkedList{
public:
	linkedList(Node<T>* head, int maxSize);
	linkedList();

	//getters
	Node<T>* getHead() const;

	//setters
	void setHead(Node<T>* head);

	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;

	void print();
	bool isItemAtEqual(int index, T elemType);
	bool isItemInList(T elemType);
	void insertEnd(T elemType);
	void insertAt(int index, T elemType);
	void removeAt(int index);
	Node<T>* retrieveNodePtrAt(int index) const;
	T retrieveAt(int index);
	void replaceAt(int index, T elemType);
	void clearList();

	linkedList& operator=(const linkedList& other);

	virtual ~linkedList();


//NODE IS TEMPLATE!!
protected:
	Node<T>* head;
	int maxSize, size;
};




#endif /* LINKEDLIST_H_ */
