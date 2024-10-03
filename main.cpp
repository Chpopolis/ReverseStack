#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

class Stack{
public:
	Stack();
	void print();
	void reverse();
private:
	stack<int> stack;
	int size;
	void insertBottom(int num);
};

Stack::Stack() {
	this->size = 5;
	for (int i = 0; i < size; i++) {
		stack.push(i+1);
	}
}

void Stack::print() {
	cout << "print stack top(): "<<stack.top()<<" "<<endl;
}
// from stack = 5,4,3,2,1 to stack = 1,2,3,4,5
void Stack::reverse() {
	if (stack.size() == 0 || stack.size() == 1) return;
	// front = 5;
	int front = stack.top();
	stack.pop(); // stack: 4,3,2,1 && front = 5
	this->reverse(); // stack = 1,2,3,4 && front  = 5
	this->insertBottom(front); // stack = 1,2,3,4,5
}

void Stack::insertBottom(int front) {
	// stack = 1,2,3,4 && front = 5
	if (stack.size() == 0) {
		stack.push(front); // stack = 5
		return;
	}
	int top = stack.top();
	stack.pop();  // top = 1, stack = 2,3,4
	this->insertBottom(front); // front = 5, top = 1, stack = 2,3,4 --> stack = 2,3,4,5
	stack.push(top); // top = 1, stack = 2,3,4,5 --> stack = 1,2,3,4,5	
}

int main() {
	Stack stk;
	stk.print();
	stk.reverse();
	stk.print();
	return 0;
}