#include "Dosage.h"

Dosage::Dosage(): minWeight(), maxWeight(), volume(0){}
Dosage::Dosage(Weight &min, Weight &max, double vol):
	minWeight(min), maxWeight(max), volume(vol){}

ostream& operator<<(ostream& out, Dosage d){
	out << d.minWeight << " to " << d.maxWeight << ": " << endl;
	out << d.volume << "mL " << endl;
	return out;
}

bool Dosage::operator>(Dosage &other){
	return ((this->volume) > other.volume);
}
bool Dosage::operator<(Dosage &other){
	return ((this->volume) < other.volume);
}
bool Dosage::operator<=(Dosage &other){
	return ((this->volume<=other.volume));
}
bool Dosage::operator>=(Dosage &other){
	return ((this->volume>=other.volume));
}
