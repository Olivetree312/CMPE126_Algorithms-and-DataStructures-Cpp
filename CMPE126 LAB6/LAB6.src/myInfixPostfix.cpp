#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include "arrayStack.h"
#include <cctype>

using namespace std;

string infixToPostfix(const string infix);
string customInfixToPostfix(const string infix);
int evaluatePostfix(const string postfix);

int main(){
	string input1 = "A + B - C";
	cout << input1 << " to postfix --> " << infixToPostfix(input1) << endl;
	cout << "using custom stack..." << endl;
	cout << input1 << " to postfix --> " << customInfixToPostfix(input1) << endl;

	input1 = "2 10 5 * +";
	string postfix = infixToPostfix(input1);
	cout << "evaluating " << postfix << " ... -> " << evaluatePostfix(postfix) << endl;

	ifstream input("test.txt");
	if(!input){
		cerr << "Error opening file" << endl;
		return 1;
	}
	while(getline(input, input1)){
		cout << input1 << " to postfix --> \n"<< infixToPostfix(input1) << endl;
	}
}

string infixToPostfix(const string infix){
	string curr;
	stringstream in(infix);
	string postfix = "";
	stack<string> ops;
	//parsing elements from input
	while(in >> curr){
		//exit loop upon semicolon ;
		if(curr == ";"){
			//DON'T BREAK --> will exit in >> curr loop
			continue;
		}
		//if curr is operator -> pop ops from stack to postfix
		//	while stack NOT empty AND top of stack has >= precedence
		//	AND while top of stack not "("
		if(curr=="+"||curr=="-"||curr=="*"||curr=="/"){
			while(!ops.empty()&&ops.top()!="("){
				if(curr=="*"||curr=="/"){
					//break because stack ops have less precedence
					if(ops.top()=="+"||ops.top()=="-")
						break;
				}
				//USING ELSE HERE WILL CAUSE INFINITE LOOP
				//	IN THE CASE OF curr == */ and ops.top()==*/
				postfix+=ops.top();
				postfix+= " ";
				ops.pop();
			}
			ops.push(curr);
		}
		else if(curr=="("){
			ops.push(curr);
		}
		//closing parenthesis -> pop from stack to postfix until ( found
		else if(curr==")"){
			while(ops.top()!="("){
				postfix+=ops.top();
				postfix+= " ";
				ops.pop();
			}
			//don't forget to pop parenthesis from stack
			ops.pop();
		}
		//in remaining cases --> curr is operand, so add to postfix
		else{
			if(curr!=";")
				postfix+=curr;
				postfix+=" ";
		}
	}
	//pop and append all remaining ops from stack to postfix
	while(!ops.empty()){
		postfix += ops.top();
		postfix += " ";
		ops.pop();
	}
	return postfix;

}

string customInfixToPostfix(const string infix){
	string curr;
	stringstream in(infix);
	string postfix = "";
	arrayStack ops(infix.length());
	//parsing elements from input
	while(in >> curr){
		//exit loop upon semicolon ;
		if(curr == ";"){
			//DON'T BREAK --> will exit in >> curr loop
			continue;
		}
		//if curr is operator -> pop ops from stack to postfix
		//	while stack NOT empty AND top of stack has >= precedence
		//	AND while top of stack not "("
		if(curr=="+"||curr=="-"||curr=="*"||curr=="/"){
			while(!ops.isEmpty()&&ops.top()!="("){
				if(curr=="*"||curr=="/"){
					//break because stack ops have less precedence
					if(ops.top()=="+"||ops.top()=="-")
						break;
				}
				//USING ELSE HERE WILL CAUSE INFINITE LOOP
				//	IN THE CASE OF curr == */ and ops.top()==*/
				postfix+=ops.top();
				postfix+= " ";
				ops.pop();
			}
			ops.push(curr);
		}
		else if(curr=="("){
			ops.push(curr);
		}
		//closing parenthesis -> pop from stack to postfix until ( found
		else if(curr==")"){
			while(ops.top()!="("){
				postfix+=ops.top();
				postfix+= " ";
				ops.pop();
			}
			//don't forget to pop parenthesis from stack
			ops.pop();
		}
		//in remaining cases --> curr is operand, so add to postfix
		else{
			if(curr!=";")
				postfix+=curr;
				postfix+=" ";
		}
	}
	//pop and append all remaining ops from stack to postfix
	while(!ops.isEmpty()){
		postfix += ops.top();
		postfix += " ";
		ops.pop();
	}
	return postfix;

}

//evaluating postfix expression:
int evaluatePostfix(const string postfix){
	int result =0;
	int num, int1, int2;
	stack<int> nums;
	string curr;
	stringstream in(postfix);
	//parsing elements from input
	while(in >> curr){
		if(isdigit(curr[0])){
			num = stoi(curr);
			nums.push(num);
		}
		//if curr is operator -> pop ops from stack to postfix
		//	while stack NOT empty AND top of stack has >= precedence
		//	AND while top of stack not "("
		if(curr=="+"||curr=="-"||curr=="*"||curr=="/"){
			int1 = nums.top();
			nums.pop();
			int2 = nums.top();
			nums.pop();
			if(curr=="+")
				result = int2 + int1;
			if(curr=="-")
				result = int2 - int1;
			if(curr=="/")
				result = int2 / int1;
			if(curr=="*")
				result = int2 * int1;
			nums.push(result);
		}
	}
	return nums.top();

}




