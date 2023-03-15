#include <iostream>
#include <string>
#include "Stack.h"
#include"StackArray.h"

bool checkBalanceBrackets(const char* text, const int maxDeep);

int main() {
	/*StackArray<int> Stack(5);
	Stack.push(1);
	Stack.push(1);
	Stack.pop();
	Stack.pop();*/
	//char* str[7] = {'(', ')', '[', ']', '{', '}'};
	const char* str = "()[]{}({[]}[{}])";	
	std::cout << checkBalanceBrackets(str, 10) << "		true" << '\n';
	str = "()";
	std::cout << checkBalanceBrackets(str, 10) << "		true" << '\n';
	str = "(8)*{5/[8-9*(2-a)]}";
	std::cout << checkBalanceBrackets(str, 10) << "		true" << '\n';
	str = "(()";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';
	str = "()}";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';
	str = "({[])}";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';
	str = "({[()]})";
	std::cout << checkBalanceBrackets(str, 2) << "		false" << '\n';
	str = "([]]))";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';
	str = "[]]))";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';
	str = "(({})){}[]]))";
	std::cout << checkBalanceBrackets(str, 10) << "		false" << '\n';


	return 0;

}
