#include <iostream>
#include "Robot.h"
using namespace std;
/****************** UNCOMMENT TO TEST MAZE CODE ***********************
bool maze_walls[5][6] = {
{1,0,0,0,0,1},
{1,0,0,0,1,1},
{1,1,0,1,0,1},
{1,0,0,0,0,1},
{1,0,1,1,0,1}
};
bool maze_floors[6][5] = {
{1,1,1,1,1},
{1,1,1,1,0},
{1,0,1,1,0},
{0,0,1,1,0},
{0,1,0,1,0},
{1,1,1,1,1}
};
void navigateMaze(Robot r, int targetx, int targety){
}
/*********************************************************************************/
int main(){
try{
Robot r(4,5);
r.move("l");
r.move("l");
r.move("u");
r.move("r");
// Result is Robot at (3, 6)
cout << "Result: " << r.getState() << endl;
r.undo(1); // Robot at (2, 6)
cout << "After undo: " << r.getState() << endl;
r.undo(2); // Robot at (3, 5)
cout << "After undo: " << r.getState() << endl;
r.redo(1); // Robot at (2, 5)
cout << "After redo: " << r.getState() << endl;
r.redo(1); // Robot at (2, 6)
cout << "After redo: " << r.getState() << endl;
//r.redo(2); // Uncommenting this statement should throw an error that
//no more redoes are possible
//cout << "After redo: " << r.getState() << endl;
r.undo(1); // Robot at (2, 5)
cout << "After undo: " << r.getState() << endl;
r.printAllOperations(); //Prints all the operations from the beginning
}
catch(const char* c){
cout << c << endl;
}
/****************** UNCOMMENT TO TEST MAZE CODE ***********************
try{
Robot r2;
navigateMaze(r2, 2, 2);
}
catch(const char* c){
cout << c << endl;
}
/*********************************************************************************/
return 0;
}



bool isOOB(int a, int b, int maxA, int maxB){
	if(a<0||b<0||a>maxA||b>maxB)
		return true;
	else
		return false;
}
