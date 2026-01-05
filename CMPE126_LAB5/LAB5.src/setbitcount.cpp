#include <iostream>

using namespace std;

//initial bits set to 0
/*int set_bit_count(int n, int &bits){
	cout << "in setbitcount with n = " << n << " and bits = " << bits << endl;
	if(n==0){
		cout << "*returning 0 with n=0*" << endl;
		return 0;
	}
	if(n%2==1){
		cout << "n%2==1 --> incrementing bits" << endl;
		bits++;
	}
	return set_bit_count(n/2, bits);
}*/

unsigned int set_bit_count(const int &n){
	cout << "in setbitcount with n = " << n << endl;
	if(n==0){
		cout << "*returning 0 with n=0*" << endl;
		return 0;
	}
	else if(n%2==1){
		unsigned int result = 1 + set_bit_count(n/2);
		cout << "n%2==1 --> incrementing bits" << endl;
		return result;
	}
	else{
		//to see unwinding --> cout goes AFTER recursive call & BEFORE return
		unsigned int result = set_bit_count(n/2);
		cout << "n%2==0" << endl;
		return result;
	}
}





