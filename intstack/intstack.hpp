# include <iostream>

class IntStack {

	IntStack();
	IntStack(int s);
	IntStack(const IntStack & other);
	~IntStack();

	int* stack;
	int size;
	int top;
	void push(int i);
	bool isempty();
	bool isfull();
	int pop();
	void print();
};