#include <stdio.h>

// implement me:
int fib(int n) {
	if(n <= 1) return n;
	return fib(n-1) + fib(n-2);
}

int main() {
	printf("after 12 months we have %d rabbits\n", fib(20));
}