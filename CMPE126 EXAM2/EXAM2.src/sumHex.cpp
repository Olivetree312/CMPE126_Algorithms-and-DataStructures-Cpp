/* COMMENTING OUT FILE SO IT DOESN'T INTEFERE W MAIN.CPP
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int sumHex(const string input);
int hexCharToInt(char c);
int main() {
int sum;
sum = sumHex("AAAA");
cout << sum << endl; //expects 40
sum = sumHex("123");
cout << sum << endl; //expects 6
sum = sumHex("C");
cout << sum << endl; //expects 12
sum = sumHex("A1B4");
cout << sum << endl; //expects 26
Comment this line if you want to try error checking
try{
sum = sumHex("CMPE");
cout << sum << endl; //should throw an error
}
catch(const char *s){
cout << s << endl;
}
//
return 0;
}

int sumHex(const string input){
	// base cases
	if(input.empty()){return 0;}
	//get decimal value of highest position hex char
	int dec = hexCharToInt(input.at(0));
	return dec + sumHex(input.substr(1));
}

int hexCharToInt(char c){
	if('0' <= c && c <= '9'){
		return int(c) -int('0');
	}
	if('A' <= c && c <= 'F'){
		return int(c) - int('A') + 10;
	}
	return 0;
}
*/
