#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int max4(int a, int b, int c, int d);

int main() {
	int a, b, c, d;
	int i = 1;
	printf("%d 입력: ",i++);
	scanf("%d", &a);
	printf("%d 입력: ", i++);
	scanf("%d", &b);
	printf("%d 입력: ", i++);
	scanf("%d", &c);
	printf("%d 입력: ", i++);
	scanf("%d", &d);

	int result = max4(a, b, c, d);
	printf("%d",result);
}

int max4(int a, int b, int c, int d)
{
	int max = a;

	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;

	return max;
}
