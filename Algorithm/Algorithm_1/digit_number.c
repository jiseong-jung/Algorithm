#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a;
	int count = 0;
	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &a);

	if (a > 0) {

		int temp_a = a;
		while (a != 0) {
			a /= 10;
			count++;
		}
		printf("%d�� %d �ڸ����̴�.\n", temp_a, count);
	}
	else
		printf("���� ������ �ƴմϴ�.\n");

} 