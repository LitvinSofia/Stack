#include <iostream>
#include <string>
#include "Stack.h"
#include"StackArray.h"
#include "QueueArray.h"

bool checkBalanceBrackets(const char* text, const int maxDeep);

int main() {
	/*StackArray<int> Stack(5);
	Stack.push(1);
	Stack.push(1);
	Stack.pop();
	Stack.pop();*/
	QueueArray<int> queue(5);
	queue.enQueue(1);
	queue.enQueue(2);
	queue.enQueue(3);
	queue.enQueue(4);
	std::cout << queue << '\n';
	queue.deQueue();
	queue.deQueue();
	std::cout << queue;
	return 0;

}
