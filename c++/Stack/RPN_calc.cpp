#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
	string rpn;
	char num_ope;
	Stack rpn_stack;
	cout << "Enter an RPN expression (e.g., 50 15 * 38 20 / + =): ";
	cin >> rpn;
	while (rpn != "=")
	{
		if (rpn != "+"&&rpn != "-"&&rpn != "*"&&rpn != "/")
			rpn_stack.push(atoi(rpn.c_str()));
		else
		{
			int num2 = rpn_stack.pop();
			int num1 = rpn_stack.pop();
			if (rpn == "+")
				rpn_stack.push(num1 + num2);
			else if (rpn == "-")
				rpn_stack.push(num1 - num2);
			else if (rpn == "*")
				rpn_stack.push(num1 * num2);
			else if (rpn == "/")
				if (num2 != 0)
					rpn_stack.push(num1 / num2);
				else
				{
					cout << "Invalid input! Divider is 0!\n";
					exit(1);
				}
		}
		cin >> rpn;
	}
	if (rpn_stack.getDepth() == 1)
		cout << "Result = " << rpn_stack.pop() << endl;
	else
		cout << "Invalid input!\n";
	
	system("pause");
	return 0;

}
