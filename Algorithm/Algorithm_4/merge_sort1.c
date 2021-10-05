#define _CRT_SECURE_NO_WARNINIGS
#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int b[], int left, int right);

int main() {
	int nx;
	int* x, * buff;

	puts("병합 정렬");
	printf("요소의 개수 : ");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(x[0]));
	buff = calloc(nx, sizeof(buff[0]));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] =  ", i);
		scanf("%d", &x[i]);
	}

	merge(x, buff, 0, nx - 1);

	puts("오름차순 정렬");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
	free(buff);

}


static void merge(int a[], int b[], int left, int right) {
	if(left<right){
		int center = (left + right) / 2;
		int len = 0;
		int a_cu;		//a cursor	
		int b_cu = 0;		//b cursor
		int k = left;

		merge(a, b, left, center);
		merge(a, b, center + 1, right);

		for (a_cu = left; a_cu < center; a_cu++)
			b[len++] = a[a_cu];

		while (b_cu <= right && b_cu < len)
			a[k++] = (b[b_cu] <= a[a_cu] ) ? b[b_cu++] : a[a_cu++];

		while (b_cu < len)
			a[a_cu++] = b[b_cu++];
	}
}