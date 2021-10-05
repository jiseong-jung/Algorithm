#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick(int a[], int left, int right) {

	int pl = left;					//cursor
	int pr = right;
	int x = a[(pl + pr) / 2];

	printf("a[%d] ~ a[%d] : {", left, right);
	for (int i = left; i < right; i++)
		printf("%d", a[i]);
	printf("%d}\n", a[right]);

	while (pl <= pr) {

		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			int temp = a[pl];
			a[pl] = a[pr];
			a[pr] = temp;

			pl++;
			pr--;
		}
	}
	if (left < pr) {
		quick(a, left, pr);
	}
	if (right > pl) {
		quick(a, pl, right);
	}


}


int main() {
	int nx;
	int* x;

	srand(time(NULL));

	puts("배열의 요소를 나눕니다.");
	printf("요소의 개수 :");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(x[0]));


	for (int i = 0; i < nx; i++) {
		x[i] = (int)rand() % 10 + 1;
		printf("%d\n", x[i]);
	}

	quick(x, 0, nx);

	//free(x);

	return 0;

}