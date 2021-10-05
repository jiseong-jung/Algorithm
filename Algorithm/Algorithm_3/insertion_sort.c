#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void insertion(int a[], int n);

int main() {
	clock_t start, end, used_time = 0;    //실행 시간 측정을 위한 변수

	srand(time(NULL));

	int nx;
	int* x;
	puts("insertion sort");
	printf("number of inputs: ");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(x[0]));

	for (int i = 0; i < nx; i++) {
		x[i] = (int)rand() % 1000+1;
	}
	start = clock();
	insertion(x, nx);
	end = clock();

	puts("insertion sort after");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	printf("\n1만개 quick정렬에 걸린 시간 : %.3lf\n", (double)(end - start)/ CLOCKS_PER_SEC);

	return 0;
}

void insertion(int a[], int n) {
	int j;

	for (int i = 1; i < n; i++) {
		int temp = a[i];
		
		for (j = i; j > 0 && a[j - 1] > temp; j--) 
			a[j] = a[j - 1];
		
		a[j] = temp;
		
	}
}