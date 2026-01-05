/*
 * Time.h
 *
 *  Created on: Feb 11, 2025
 *      Author: oliviachen
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

class Time{
public:
	Time();
	Time(int hour);
	Time(int hour, int minute);

	int getHour() const;
	int getMinute() const;
	void setHour(int hour);
	void setMinute(int minute);

	friend ostream& operator <<(ostream& out, Time t);

private:
	int hour, minute;
	bool isValidHour(int hour);
	bool isValidMinute(int minute);
};

#endif /* TIME_H_ */
