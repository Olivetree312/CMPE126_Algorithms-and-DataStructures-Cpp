/*
 * lab1-cmpe126.cpp
 *
 *  Created on: Feb 4, 2025
 *      Author: oliviachen
 */
#include <iostream>
//INCLUDE CLASS HEADER FILE BECAUSE
//OBJECT FILES LINKED DURING COMPILATION
#include "complexNumber.h"
//file operations
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

static int err=0;

complexNumber getNum(string s);

int main(){
	//TESTING LP TASKS --> SUCCESS!
	/*complexNumber c1;
	complexNumber c2 (1,-5);
	complexNumber c3(2);
	int realNum = 3;
	cout << c1;
	cout << c2 << "+" << c3;
	cout << c2+c3;
	c1 = c1+realNum;
	cin >> c2;
	cout << c2*c3;
	c3 = c2-c1;
	*/
	//reading from complexInput.txt
	ifstream input("complexInput.txt");
	ofstream output("complexOutput.txt");
	if(!input.is_open()){
		output << "Error opening input file." << endl;
		//terminates program immediately
		//only return 0 calls destructors of local object
		exit(1);
	}
	if(!output.is_open()){
			output << "Error opening output file." << endl;
			//terminates program immediately
			//only return 0 calls destructors of local object
			exit(1);
		}
	complexNumber first, second;
	//reading from input, parsing complexNumber
	string line;
	if(!getline(input, line)){
		output << "Error: line not found" << endl;
		exit(1);
	}
	first = getNum(line);
	if(err==1){
		output << "Error retrieving first complex number." << endl;
	}
	//retreiving operator
	char op;
	if(!input.get(op)){
		output << "Error: operator not found" << endl;
		exit(1);
	}
	//moving onto next line since get() doesn't do that
	string var;
	getline(input, var);
	if(!getline(input, line)){
		output << "Error: line not found" << endl;
		exit(1);
	}
	second = getNum(line);
	if(err==1){
		output << "Error retrieving second complex number." << endl;
	}

	if(op=='+'){
		output << first + second << endl;
	}
	else if(op=='-'){
		output << first - second << endl;
		}
	else if(op=='*'){
		output << first * second << endl;
		}
	else{
		output << "Error: invalid operation." << endl;
	}

	//closing files
	input.close();
	output.close();
}

//parses complexNumber from string
//changes err to 1 if unable to retrieve
complexNumber getNum(string s){
int index=0;
int real=1;
int imag=1;
string num="";
//checking for minus sign for a
if(s[0]=='-'){
	real*=-1;
	index++;
}
for(int i=index; i<s.size(); i++){
	if(!isdigit(s[i])&&(s[i]!='+'&&s[i]!='-')){
		err = 1;
		break;
	}
	else if(s[i]=='+'||s[i]=='-'){
		index++;
		break;
	}
	else if(isdigit(s[i])){//if no error, add digit to num string
		num+=s[i];
		index++;
	}
}
cout << "num: "<< num << endl;
int temp = stoi(num);
real*=temp;
num="";
//checking for - operator
if(s[index]=='-'){
	imag*=-1;
	index++;
}
for(int i=index; i<s.size(); i++){
	if(s[i]=='i'&&num.empty()){
		num+="1";
		break;
	}
	else if(!isdigit(s[i])&&s[i]!='i'){
		err = 1;
		break;
	}
	else if(isdigit(s[i])){//if no error, add digit to num string
		num+=s[i];
	}
}
cout << "imag num: " << num << endl;
temp = stoi(num);
imag*=temp;

complexNumber ans(real, imag);
return ans;
}

