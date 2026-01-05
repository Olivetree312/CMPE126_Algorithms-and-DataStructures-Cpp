#include <iostream>
#include <fstream>
#include "Student.h"
#include <string>
using namespace std;
#define MAXSTUDENTS 64
int read(string filename, Student* students){
	ifstream fin(filename);
	if (!fin.is_open()) {
	    cerr << "Error: file unopened " << filename << endl;
	    return 0;
	}
	int index = 0;
	Student temp;
	string word;
	while(getline(fin,word, ',') && index < MAXSTUDENTS){
		temp.setId(word);
		getline(fin, word, ',');
		temp.setFirstName(word);
		getline(fin, word);
		temp.setLastName(word);
		students[index++] = temp;
		//printing just initialized Students
		cout << index-1 << ".) " << students[index-1].getId() << "," << students[index-1].getFirstName() <<
				"," << students[index-1].getLastName() << endl;
	}
	return index-1;
}
int basicSearch(Student* students, string name, int num_students){
	for(int i = 0; i < num_students; i++){
		if(students[i].getLastName() == name){
			return i;
		}
	}
	return -1;
}
void binarySearch(Student* students, int num_students){
	string student;
	cout << "Enter last name to search for: ";
	cin >> student;
	int target = student[0];
	int temp;
	int left = 0;
	int right = num_students-1;
	while(left <= right){
		int mid = left+(right-left)/2;
		string s = students[mid].getLastName();
		int curr = s[0];
		if(students[mid].getLastName() == student){
			temp = mid;
			break;
		}
		else if(curr < target){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
		temp = -1; //if not found
	}
	if(temp==-1){
		cout << "Student not found" << endl;
		return;
	}
	cout << temp << " ";
	//getting rest of students with same last name
	while((temp+1)<num_students){
		if(students[temp+1].getLastName()==student){
			temp++;
			cout << temp << " ";
		}
		else
			break;
	}
	while((temp-1)>=0){
		if(students[temp-1].getLastName()==student){
			temp--;
			cout << temp << " ";
		}
		else
			break;
	}
}
int ternaryHelper(string student, Student* students, int low, int high, int target){
	//base case for recursion
	if(low>high){return -1;}
	int mid1 = low + (high-low)/3;
	string s = students[mid1].getLastName();
	int curr1 = s[0];
	int mid2 = high - (high-low)/3;
	s = students[mid2].getLastName();
	int curr2 = s[0];
	if(students[mid1].getLastName()==student){
		return mid1;
	}
	if(students[mid2].getLastName()==student){
		return mid2;
	}
	if(target < curr1){
		return ternaryHelper(student, students, low, mid1-1, target);
	}
	else if(target < curr2 &&target >curr1){
		return ternaryHelper(student, students, mid1+1, mid2-1, target);
	}
	else{
		return ternaryHelper(student, students, mid2+1, high, target);
	}
	return -1;
}
void ternarySearch(Student* students, int num_students){
	string student;
	cout << "Enter last name to search for: ";
	cin >> student;
	int target = student[0];
	int low = 0;
	int high = num_students-1;
	int temp = ternaryHelper(student,students, low, high, target);
	if(temp==-1){
		cout << "Student not found" << endl;
		return;
	}
	cout << temp << " ";
	while((temp+1)<num_students){
		if(students[temp+1].getLastName()==student){
			temp++;
			cout << temp << " ";
		}
		else
			break;
	}
	while((temp-1)>=0){
		if(students[temp-1].getLastName()==student){
			temp--;
			cout << temp << " ";
		}
		else
			break;
	}
}
void searchAll(Student* students, int num_students){
	string student;
	cout << "Enter last name to search for: ";
	cin >> student;
	int temp = basicSearch(students, student, num_students);
	if(temp==-1){
		cout << "Student not found" << endl;
		return;
	}
	cout << temp << " ";
	while(true){
		if(students[temp+1].getLastName()==student){
			temp++;
			cout << temp << " ";
		}
		else
			break;
	}
}
int main() {
	//testing search by last name
	Student* students = new Student[64];
	int num_students = read("students.txt", students)+1;
	cout << "last updated index in array (zero-based indexing): "<< num_students-1 << endl;
	cout << "testing searchAll..." << endl;
	searchAll(students, num_students);
	cout << "testing binarySearch..." << endl;
	binarySearch(students, num_students);
	cout << "testing ternarySearch..." << endl;
	ternarySearch(students, num_students);
}
