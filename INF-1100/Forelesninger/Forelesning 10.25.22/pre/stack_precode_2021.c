#include <stdio.h>

char STACK[128];              // holds stack data
int top = 0;                  // points to top of stack

void push(char ch) {          // implement me
	STACK[top] = ch;
	top = top + 1;
}

char pop() {                  // implement me
	top = top - 1;
	return STACK[top];
}

int main() {
	push(1); push(2); push(12);

	// should print 3 2 1 
	printf("%d %d %d\n", pop(), pop(), pop());
}