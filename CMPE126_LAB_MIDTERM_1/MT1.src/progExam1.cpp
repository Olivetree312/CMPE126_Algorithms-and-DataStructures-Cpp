#include <iostream>
#include "Dosage.h"
#include "Weight.h"
#include "Baby.h"
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main(){
//6. TESTING FUNCTIONALITY OF OL OP
	Weight w1(6,0);
	Weight w2(11,5);
	Weight w3(7,0);
	Weight w4(12, 6);

	cout << "Weight 1: " << w1 << endl;
	cout << "Weight 2: " << w2 << endl;
	cout << "Weight 3: " << w3 << endl;
	cout << "Weight 4: " << w4 << endl;
	cout << "Creating Dosage 1 with minimum Weight 1, maximum Weight 2, Dosage: 1.25 mL" << endl;
	Dosage dose1(w1, w2, 1.25);
	cout << dose1 << endl;
	cout << "Creating Dosage 2 with minimum Weight 3, maximum Weight 4, Dosage: 2.5 mL" << endl;
	Dosage dose2(w3, w4, 2.5);
	cout << dose2 << endl;

	//boolalpha needed to output true/false to stream instead of 0 or 1
	cout << boolalpha;
	cout << "Dose 1 > Dose 2?: " << (dose1>dose2) << endl;
	cout << "Dose 1 >= Dose 2?: " << (dose1>=dose2) << endl;
	cout << "Dose 1 < Dose 2?: " << (dose1<dose2) << endl;
	cout << "Dose 1 <= Dose 2?: " << (dose1<=dose2) << endl;
	cout << endl;

//7. ARRAY OF DOSAGES from dosage_chart.txt
	ifstream inputFile("dosage_chart.txt");
	string line;
	int numDoses;
	if(!inputFile.is_open()){
		cerr << "Error opening dosage_chart.txt" << endl;
		exit(1);
	}
	inputFile >> numDoses;
	//cin leaves \n with input buffer --> must get rid
	inputFile.ignore();
	//creating pointer to Dosage array of size numDoses
	Dosage* doseList = new Dosage[numDoses];
	int count=0;
	while(getline(inputFile, line)){
		int minLbs, minOz, maxLbs, maxOz;
		double vol;
		//parsing obtained line string manually
		stringstream ss(line);
		//extracting both weights and discarding whitespace
		ss >> minLbs >> ws;
		//holders for "lbs" and "oz"
		string lbs, oz, mL;
		ss >> lbs >> minOz >> oz;
		//skipping dash
		string dash;
		ss >> dash;
		ss >> maxLbs >> lbs >> maxOz >> oz;
		//extracting volume after :
		string volStr;
		ss >> ws;
		ss.ignore(2); //skipping ": "
		ss >> vol >> mL;


		Weight minW(minLbs, minOz);
		Weight maxW(maxLbs, maxOz);
		//initializing dose element in array
		doseList[count] = Dosage(minW, maxW, vol);
		count++;
	}
	for(int i=0; i<numDoses; i++){
		cout << doseList[i] << endl;
	}

//9 & 10. BABY WITH WEIGHT, NAME, DOSE
	Baby babe("Steve", w1, doseList, numDoses);
	cout << babe << endl;

	//babe+5;


	//close the file because good practice :))
	inputFile.close();
	//freeing memory
	delete[] doseList;
}



