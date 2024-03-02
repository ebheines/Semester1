#include <stdio.h>

char STACK[128];              
int top = 0;                  

void push(char ch) {
	STACK[top] = ch;          
	top = top + 1;            
}

char pop() {
	top = top - 1;            
	return STACK[top];        
}

/*
	The function below should be
	
	void subtract() {
		/// something
	}
	
	No arguments!
*/
// int factorial(int n){
	// if(n == 1) return 1;
	// n*factorial(n-1);
// }

void subtract() {
	char a = pop();       // push return val on stack
	char b = pop();
	push(a - b);
}

int main() {
	// something needs to change here also
	push(5);
	push(6);
	subtract();
	printf("6 - 5 = %d\n", pop());
	//factorial(5);
	//printf("%d	\n", factorial(10));
}