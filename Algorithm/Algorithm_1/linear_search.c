#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void search_idx(const int ary[], int n, int key, int idx[]);
void init(int p[], int size);


int main() {
	
	int key, idx;
	int* p;
	int* tmp;
	int size;
	int arr[5];
	

	printf("크기 설정\n>");
	scanf("%d",&size);

	printf("키 설정\n>");
	scanf("%d", &key);

	p = calloc(size, sizeof(int));
	tmp = calloc(3, sizeof(int));

	init(p, size);

	search_idx(p, size, key, tmp);

	free(p);
	free(tmp);

	return 0;

}

void init(int p[], int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		p[i] = rand() % 100;
	}

	for (int i = 0; i < size; i++) {
		printf("x[%d]= %d, ", i, p[i]);
	}
	puts("");
}

void search_idx(const int ary[], int n, int key, int idx[]) {

	int count = 0;
	int de = 0;
	int ho = 0;

	for (int i = 0; i < n; i++) {
		if (ary[i] == key) {
			idx[ho++] = i;
			if (ho % 3 == 0) {
				realloc(idx, sizeof(int) * 3);
			}
			//idx[i] = ary[i];
			count++;
		}
	}

	printf("검색 값: %d\n",key);
	printf("key와 같은 개수는 %d개\n", count);

	for (int i = 0; i < ho; i++) {
		if (idx[i] != 0)
			printf("idx[%d] = %d\n", de++, idx[i]);
	}

	puts("");

}