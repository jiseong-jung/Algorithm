#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long factorial(int n);
long factorial1( int mul, int n);

int main() {

	int x;
	printf("정수를 입력하시오: ");
	scanf("%d",&x);
	printf("%d의 순차 곱셉의 값은 %d입니다.\n", x, factorial(x));
	printf("%d의 순차 곱셉의 값은 %d입니다.\n", x, factorial1(1,x));

	return 0;
}

long factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

long factorial1(int mul, int n) {
	if (n == 0)
		return mul;

	return factorial1(n * mul, n - 1);

}