#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	int* a;
	int na;

	printf("����� ����");
	scanf("%d", &na);

	a = calloc(na, sizeof(int));

	if (a == NULL) {
		printf("memory fail");
	}
	else {
		printf("%d���� ������ �Է��ϼ���.\n",na);

		for (int i = 0; i < na; i++) {
			printf("a[%d] :", i);
			scanf("%d", &a[i]);
		}
		printf("�� ��� ���� �Ʒ��� �����ϴ�.\n");

		for (int i = 0; i < na; i++) {
			printf("a[%d]= %d\n", i, a[i]);
		}

		free(a);
	}
	
	return 0;
}