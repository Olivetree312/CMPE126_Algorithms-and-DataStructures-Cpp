#ifndef ROBOT_H_
#define ROBOT_H_
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Robot {
public:
	Robot();
	Robot(int, int);

	void move(string);
	void undo(int);
	void redo(int);
	string getState();
	void printAllOperations();

	virtual ~Robot();
//added private variables
private:
	stack<string> undoStack;
	stack<string> redoStack;
	vector<string> history;
	int x,y;
};
#endif /* ROBOT_H_ */
