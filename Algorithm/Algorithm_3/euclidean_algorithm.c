#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//최대 공약수 구하기 유클리드 호제법
int gcd(int a, int b);

int main() {

	int a, b;
	int result = 0;

	printf("Find a GCD\n");
	printf("first value: ");
	scanf("%d",&a);
	printf("second value: ");
	scanf("%d", &b);

	result = gcd(a, b);
	printf("result is : %d\n",result);


	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		gcd(b, a % b);
}