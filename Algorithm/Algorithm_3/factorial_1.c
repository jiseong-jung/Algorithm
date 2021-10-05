#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int factorial(int a);

int main() {

	int x;
	printf("input number: ");
	scanf("%d", &x);
	printf("number %d factorial result is %d.\n", x, factorial(x));

	return 0;
}

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
	return result;
}