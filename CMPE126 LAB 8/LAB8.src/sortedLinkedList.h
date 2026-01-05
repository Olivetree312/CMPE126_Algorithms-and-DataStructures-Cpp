/*
 * sortedLinkedList.h
 *
 *  Created on: Feb 25, 2025
 *      Author: oliviachen
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include "linkedList.h"
#include <vector>

template <class T>
class sortedLinkedList : public linkedList<T>{
public:
	sortedLinkedList(Node<T>* head, int maxSize);
	sortedLinkedList(linkedList<T>& list);

	void sortList();
};



#endif /* SORTEDLINKEDLIST_H_ */
