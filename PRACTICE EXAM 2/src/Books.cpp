#include <iostream>
#include <fstream>
using namespace std;
#define MAXBOOKS 64
int read(string filename, string* books){
ifstream fin(filename);
int index = 0;
while(!fin.eof() && index < MAXBOOKS){
getline(fin, books[index++]);
}
return index;
}
int exponentialSearch(string* books, string element, int num_books);
void addBook(string book, string* books);
// void addBooks(string* newbooks, string* books); // Uncomment to implement bonus
int main() {
string* books = new string[MAXBOOKS];
int num_books = read("books.txt", books);
/*******************************************************
* TODO: Implement your code here:
* 1. Take user input - search string
* 2. Search for the book using exponentialSearch
* 3. Take user input to add book to the list
* 4. Add the book using addBook
*******************************************************/
delete [] books;
return 0;
}
