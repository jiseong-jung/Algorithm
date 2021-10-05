//selection sort는 index순서에 영향 x, 안정성 x
#include<stdio.h>
#include<stdlib.h>

int trance = 0;
int compare = 0;
void selection(int a[], int n);

int main() {
	int nx;
	int* x;
	puts("selection sort");
	printf("number of inputs: ");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(x[0]));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	selection(x, nx);
	puts("selection sort after");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	printf("compare : %d\n", compare);
	printf("trance : %d\n", trance);
	compare = 0;
	trance = 0;

	return 0;
}

void selection(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			compare++;
			if (a[j] < a[min]) {
				min = j;
			}
		}

		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		trance++;
	}
}