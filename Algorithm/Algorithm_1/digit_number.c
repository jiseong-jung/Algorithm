#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a;
	int count = 0;
	printf("양의 정수를 입력하시오: ");
	scanf("%d", &a);

	if (a > 0) {

		int temp_a = a;
		while (a != 0) {
			a /= 10;
			count++;
		}
		printf("%d는 %d 자리수이다.\n", temp_a, count);
	}
	else
		printf("양의 정수가 아닙니다.\n");

} 