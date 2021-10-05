//bubble sort는 같은 값이 있을때 index 순서대로 정렬, 안전성 o

#include<stdio.h>
#include<stdlib.h>

int trance = 0;
int compare = 0;

void bubble(int a[], int n);
void r_bubble(int a[], int n);
//void selection(int a[], int n);

int main() {
	int nx;
	int* x;
	puts("bubble sort");
	printf("number of inputs: ");
	scanf("%d",&nx);

	x = calloc(nx, sizeof(x[0]));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}

	//오름차순
	bubble(x, nx);

	puts("buble after");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	printf("compare : %d\n", compare);
	printf("trance : %d\n", trance);
	compare = 0;
	trance = 0;

	//내림차순
	r_bubble(x, nx);

	puts("buble after");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	printf("compare : %d\n", compare);
	printf("trance : %d\n", trance);
	compare = 0;
	trance = 0;

	//selection(x, nx);
	//puts("buble after");
	//for (int i = 0; i < nx; i++) {
	//	printf("x[%d] = %d\n", i, x[i]);
	//}
	//printf("compare : %d\n", compare);
	//printf("trance : %d\n", trance);
	//compare = 0;
	//trance = 0;
	free(x);

	return 0;
}

void bubble(int a[], int n) {
	int temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			compare++;
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				trance++;
			}
		}
	}
}

void r_bubble(int a[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <n-1-i ; j++) {
			compare++;
			if (a[j] < a[j+1] ) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				trance++;
			}
			
		}
	} 
}

//void selection(int a[], int n) {
//	for (int i = 0; i < n - 1; i++) {
//		int min = i;
//		for (int j = i + 1; i < n; j++) {
//			if (a[j] < a[min]) {
//				min = j;
//			}
//		}
//
//		int temp = a[i];
//		a[i] = a[min];
//		a[min] = temp;
//	}
//}