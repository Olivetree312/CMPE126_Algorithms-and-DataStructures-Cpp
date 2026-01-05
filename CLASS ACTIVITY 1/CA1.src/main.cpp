/*
 * CLASS_ACTIVITY1.cpp
 *
 *  Created on: Jan 30, 2025
 *      Author: oliviachen
 *
	 * ADDITIONAL EXTENSIONS:
	 * 1. operator overlaoding << in each Class.cpp file
	 * 2. operator overloading >> in each Class.cpp file
	 * 3. operator overloading = in each Class.cpp file
	 * 4. global function giveTreat overloading in main.cpp file
	 *
 */
#include <iostream>
#include <string>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

//NEED FUNCTION PROTOTYPE/ signatures
void giveTreat(Cat&);
void giveTreat(Dog&);

// Main function to test the classes
int main() {
// Create an instance of Animal
cout << "Creating animal instances" << endl;
Animal genericAnimal;
cout << "Enter animal info: " << endl;
cin >> genericAnimal;
cout << genericAnimal;
// Create an instance of Dog
Dog dog;// NO PARENTHESES
cout << "Enter dog info: " << endl;
cin >> dog;
cout << dog << endl;
// Create an instance of Cat
Cat cat;
cout << "Enter cat info: " << endl;
cin >> cat;
cout << cat << endl;

cout << "Testing animal sounds: " << endl;
cout << "The Animal says: ";
genericAnimal.makeSound();
cout << "The Dog says: ";
dog.makeSound();
cout << "The Cat says: ";
cat.makeSound();

// Additional testing
// Set attributes using setters and test getters
cout << "\nResetting animal attributes" << endl;
cat.setColor("Calico");
dog.setBreed("Poodle");
cout << cat << endl;
cout << dog << endl;

cout << "Giving each animal a treat: " << endl;
giveTreat(dog);
giveTreat(cat);
// Test polymorphism with makeSound()
Dog d;
Cat c;
Animal* catPtr = &c;
Animal* dogPtr = &d;

//animal ptr, but calls cat sound
cout << "The cat pointer says: ";
catPtr->makeSound();
//animal ptr but calls dog sound
cout << "The dog pointer says: ";
dogPtr->makeSound();

return 0;
}

//global overloading: giving the correct type of treat to each animal
void giveTreat(Cat& a){
	cout << "Giving " << a.getName() << " a cat treat." << endl;
}
void giveTreat(Dog& a){
	cout << "Giving " << a.getName() << " a dog treat." << endl;
}
