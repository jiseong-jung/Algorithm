#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void recur(int n);

int main() {

	int x;
	printf("input decimal : ");
	scanf("%d",&x);
	recur(x);

	return 0;
}	

void recur(int n){

	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}
