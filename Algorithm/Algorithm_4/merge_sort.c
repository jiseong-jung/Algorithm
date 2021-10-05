#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int na, int b[], int nb, int c[]) {
	int pa = 0;
	int pb = 0;
	int pc = 0;

	while (pa < na && pb < nb) {
		c[pc++] = (a[pa] > a[pb]) ? a[pa++] : b[pb++];
	}

	while (pa < na) {
		c[pc++] = a[pa++];
	}
	while (pb < nb) {
		c[pc++] = b[pb++];
	}


}

int main() {
	int na, nb;
	int* a, * b, * c;

	printf("a 요소 개수 :");
	scanf("%d",&na);

	printf("b 요소 개수 :");
	scanf("%d", &nb);

	a = calloc(na, sizeof(a[0]));
	b = calloc(nb, sizeof(b[0]));
	c = calloc(na + nb, sizeof(c[0]));

	printf("a[0] :");
	scanf("%d", &a[0]);

	for (int i = 1; i < na; i++) {
		do {
			printf("a[%d]: ", i);
			scanf("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}

		printf("b[0] :");
		scanf("%d", &a[0]);

	for (int i = 1; i < nb; i++) {
		do {
			printf("b[%d]: ", i);
			scanf("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}
		
	merge(a, na, b, nb, c);

	puts("After Merge");

	for (int i = 0; i < na + nb; i++)
		printf("c[%2d] = %2d\n", i, c[i]);

	free(a);
	free(b);
	free(c);


}