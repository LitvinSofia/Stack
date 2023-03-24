#include <iostream>
#include "StackArray.h"

bool checkBalanceBrackets(const char* text, const int maxDeep) {
	StackArray<char> stack(maxDeep);
	while (*text && stack.getTop() <= maxDeep) {
		if (*text == '(' || *text == '{' || *text =='[') {
			stack.push(*text);
			text++;
			continue;
		}
		if (*text == ')') {
			if (stack.getTopElement() == '(') {
				stack.pop();
				text++;
				continue;
			}
			else {
				return false;
			}
		}
		if (*text == '}') {
			if (stack.getTopElement() == '{') {
				stack.pop();
				text++;
				continue;
			}
			else {
				return false;
			}
		}
		if (*text == ']') {
			if (stack.getTopElement	() == '[') {
				stack.pop();
				text++;
				continue;
			}
			else {
				return false;
			}
		}
		text++;
	}
	return stack.isEmpty();
}