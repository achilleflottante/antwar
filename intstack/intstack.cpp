#include <iostream>
#include "intstack.hpp"

IntStack::IntStack() : size(100), stack(new int[size]), top(0) {}
IntStack::IntStack(const int s) : size(s), stack(new int[size]), top(0) {}
 


bool IntStack::isfull() {
	return size == top

};

bool IntStack::isempty() {
	return top == 0;
};

int IntStack::pop() {
	top = top - 1;
	return stack[top+1];
};

void IntStack::push(int i) {
	if (isfull() == false) {
		stack[top] = i;
		top ++;
	};
};

void IntStack::print() {
	std::cout << "[";
	for (int i = 0; i < size; i++){
		std::cout << stack[i];
		std::cout << ",";
	} ;
	std::cout << "]";

};