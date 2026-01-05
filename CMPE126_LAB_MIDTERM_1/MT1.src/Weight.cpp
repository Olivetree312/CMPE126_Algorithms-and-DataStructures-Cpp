#include "Weight.h"

using namespace std;

Weight::Weight(): pounds(0), ounces(0){}
Weight::Weight(int pounds, int ounces): pounds(pounds), ounces(ounces){}
Weight::Weight(const Weight &w){
	this->pounds = w.pounds;
	this->ounces = w.ounces;
}
int Weight::getPounds(){return pounds;}
int Weight::getOunces(){return ounces;}
void Weight::setPounds(int num){
	if(validPounds(num))
		pounds = num;
	else
		throw invalid_argument("Pounds must be positive.");
}
void Weight::setOunces(int num){
	if(validOunces(num))
		ounces = num;
	else
		throw invalid_argument("Ounces must be in range 0-15");
	}
ostream& operator<<(ostream& out, Weight& w){
	out << w.pounds << " lbs, " << w.ounces << " oz ";
	return out;
}

bool Weight:: operator<=(Weight &other){
	if(this->pounds > other.pounds)
		return false;
	if(this->pounds < other.pounds)
		return true;
	if(this->pounds==other.pounds){
		if(this->ounces == other.ounces||this->ounces<other.ounces)
			return true;
		else
			return false;
	}
	else
		return false;
}

Weight operator+(Weight& a, Weight& b){
	int p, o;
	p = a.getPounds()+b.getPounds();
	o = a.getOunces()+b.getOunces();
	return Weight(p,o);
}
bool Weight:: operator>=(Weight &other){
	if(this->pounds < other.pounds)
		return false;
	if(this->pounds > other.pounds)
		return true;
	if(this->pounds==other.pounds){
		if(this->ounces == other.ounces||this->ounces>other.ounces)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Weight:: validPounds(int num){
		if(num>0)
			return true;
		else
			return false;
	}
bool Weight::validOunces(int num){
	if(num>=0&&num<=15)
		return true;
	else
		return false;
}
