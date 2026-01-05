#include "Baby.h"

Baby::Baby(): name("N/A"), weight(), dose(){}
Baby::Baby(string name, Weight &weight, Dosage* doseList, int listLength):
		name(name), weight(weight){
	bool isDose = false;
	for(int i=0; i< listLength; i++){
		if((weight <= doseList[i].maxWeight)&&(weight>=doseList[i].minWeight)){
			dose = doseList[i];
			isDose = true;
		}
		if(!isDose)
			cerr << "no available doses found in list" << endl;
	}

}
Baby::Baby(string name, Weight &weight, Dosage &dose):
		name(name), weight(weight), dose(dose){}
string Baby::getName(){return name;}
	Weight Baby::getWeight(){return weight;}
	Dosage Baby::getDosage(){return dose;}

	void Baby::setName(string name){this->name = name;}
	void Baby::setWeight(Weight &weight){this->weight = weight;}
	void Baby::setDosage(Dosage &dose){this->dose = dose;}

	ostream& operator<<(ostream& out, Baby &b){
		out << "Name: " << b.name << endl;
		out << "Weight: " << b.weight;
		out << "Dose: " << b.dose;
		return out;
	}




