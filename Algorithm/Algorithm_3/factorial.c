#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long factorial(int n);
long factorial1( int mul, int n);

int main() {

	int x;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d",&x);
	printf("%d�� ���� ������ ���� %d�Դϴ�.\n", x, factorial(x));
	printf("%d�� ���� ������ ���� %d�Դϴ�.\n", x, factorial1(1,x));

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