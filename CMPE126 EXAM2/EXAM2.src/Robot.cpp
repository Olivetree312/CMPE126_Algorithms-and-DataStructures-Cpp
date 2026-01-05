#include "Robot.h"

using namespace std;

Robot::Robot(): x(0), y(0){}
Robot::Robot(int r, int c): x(r), y(c){}

//must store every move in history vector
void Robot::move(string c){
	undoStack.push(c);
	//need to empty redo stack
	while(!redoStack.empty()){
		redoStack.pop();
	}
	if(c=="l"){
		x-=1;
		history.push_back("l");
	}
	if(c=="r"){
		x+=1;
		history.push_back("r");
	}
	if(c=="u"){
		y+=1;
		history.push_back("u");
	}
	if(c=="d"){
		y-=1;
		history.push_back("d");
	}
	if(c!="l"&&c!="r"&&c!="u"&&c!="d"){
		cout << "invalid operation" << endl;
	}

}
//performs inverse of move to undo
void Robot::undo(int moves){
	for(int i=0; i<moves; i++){
		string before = undoStack.top();
		if(before=="l"){x+=1;}
		if(before=="r"){x-=1;}
		if(before=="u"){y-=1;}
		if(before=="d"){y+=1;}
		undoStack.pop();
		//you can redo your undoes
		redoStack.push(before);
		history.push_back("undo");
	}
}
//record undo and redoes in history vector
void Robot::redo(int moves){
	for(int i=0; i<moves && !redoStack.empty(); i++){
		string again = redoStack.top();
		redoStack.pop();
		//you can undo your redoes
		undoStack.push(again);
		if(again=="l"){x-=1;}
		if(again=="r"){x+=1;}
		if(again=="u"){y+=1;}
		if(again=="d"){y-=1;}
		history.push_back("redo");
	}
}

//returns string of (x,y) position
string Robot::getState(){
	string pos = "(" + to_string(x) + ", " + to_string(y) +")";
	return pos;
}
void Robot::printAllOperations(){
	for(int i=0; i<history.size(); i++){
		if(history.at(i)=="l")
			cout << "left" << endl;
		else if(history.at(i)=="r")
			cout << "right" << endl;
		else if(history.at(i)=="u")
			cout << "up" << endl;
		else if(history.at(i)=="d")
			cout << "down" << endl;
		else
			cout << history.at(i) << endl;
	}
}

Robot::~Robot(){}



