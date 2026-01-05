#ifndef HASHTABLECHAINING_H_
#define HASHTABLECHAINING_H_

struct Node{
	int data;
	Node* next;
	Node(int data): data(data){}
};

//manually linking Nodes because don't need that many functions of linkedList

//INSTEAD OF HASHING TO NEXT INDEX --> LINK TO LIST AT INDEX
class HashTableChaining{
private:
	//need * for dynamic arr, then * for node ptrs -> dynamic arr of ptrs
	Node** nodeArr;
	int HTSize;

public:
	HashTableChaining();
	HashTableChaining(int size);

	void print();
	//uses chaining
	bool insert(int val);
	int search(int key);
	//VIRTUAL destructor needed
	virtual ~HashTableChaining();
};

#endif /* HASHTABLECHAINING_H_ */
