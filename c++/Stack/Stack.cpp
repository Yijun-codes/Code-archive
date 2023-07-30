#include <iostream>
#include <fstream>
#include "Stack.h"
#include <string>
using namespace std;

Stack::Stack(){

	count = 0;
}

void Stack::push(int e){
	if (Stack::getDepth() == 200)
	{
		cout << "Stack full! Program exit.\n";
		exit(1);
	}
	else
		elements[count++] = e;
}

int Stack::pop(){
	if (Stack::isEmpty())
	{
		cout << "Stack empty! Program exit.\n";
		exit(1);
	}
	else
		return elements[--count];
}

bool Stack::isEmpty(){
	if (count == 0){
		return 1;
	}
	else return 0;
}

int Stack::getDepth(){
	return count;
}







