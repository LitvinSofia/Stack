#include "Stack.h"
#include"StackArray.h"

int main() {
	StackArray<int> Stack(-1);
	Stack.push(1);
	Stack.push(1);
	Stack.push(1);
	Stack.pop();
	Stack.pop();
	Stack.pop();
	
	std::cout << Stack;
	return 0;
}