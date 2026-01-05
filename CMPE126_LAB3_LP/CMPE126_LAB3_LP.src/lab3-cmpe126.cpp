#include <iostream>
#include "arrayList.h"

using namespace std;

int main() {
    // Create an arrayList of type int with a max size of 10
    arrayList<int, 10> myList("int", 5);

    cout << "=== Basic Function Tests ===" << endl;

    // Test isEmpty
    cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;

    // Test isFull
    cout << "Is list full? " << (myList.isFull() ? "Yes" : "No") << endl;

    // Test listSize
    cout << "Current list size: " << myList.listSize() << endl;

    // Test maxListSize
    cout << "Maximum list size: " << myList.maxListSize() << endl;

    // Test print (before inserting elements)
    cout << "List contents before insertions: ";
    myList.print();

    cout << "\n=== High-Priority Function Tests ===" << endl;

    // Test insertEnd
    cout << "\nInserting 10, 20, 30 at the end..." << endl;
    myList.insertEnd(10);
    myList.insertEnd(20);
    myList.insertEnd(30);
    myList.print();

    // Test insertAt
    cout << "\nInserting 15 at index 1..." << endl;
    myList.insertAt(1, 15);
    myList.print();

    // Test removeAt
    cout << "\nRemoving element at index 2..." << endl;
    myList.removeAt(2);
    myList.print();

    // Test retrieveAt
    cout << "\nRetrieving element at index 1: " << myList.retrieveAt(1) << endl;

    // Test replaceAt
    cout << "\nReplacing element at index 0 with 99..." << endl;
    myList.replaceAt(0, 99);
    myList.print();

    // Test isItemAtEqual
    cout << "\nChecking if element at index 0 is 99: ";
    cout << (myList.isItemAtEqual(0, 99) ? "True" : "False") << endl;

    // Test clearList
    cout << "\nClearing the list..." << endl;
    myList.clearList();
    myList.print();
    cout << "Is list empty after clearing? " << (myList.isEmpty() ? "Yes" : "No") << endl;

    cout << "\n=== Operator= Test ===" << endl;
    arrayList<int, 10> anotherList("int", 5);
    anotherList.insertEnd(5);
    anotherList.insertEnd(15);
    anotherList.insertEnd(25);

    cout << "Copying anotherList to myList..." << endl;
    myList = anotherList;
    myList.print();

    return 0;
}
