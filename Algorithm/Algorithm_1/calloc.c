#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	int* a;
	int na;

	printf("요소의 개수");
	scanf("%d", &na);

	a = calloc(na, sizeof(int));

	if (a == NULL) {
		printf("memory fail");
	}
	else {
		printf("%d개의 정수를 입력하세요.\n",na);

		for (int i = 0; i < na; i++) {
			printf("a[%d] :", i);
			scanf("%d", &a[i]);
		}
		printf("각 요소 값은 아래와 같습니다.\n");

		for (int i = 0; i < na; i++) {
			printf("a[%d]= %d\n", i, a[i]);
		}

		free(a);
	}
	
	return 0;
}