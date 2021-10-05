#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int bin_search(const int ary[], int len, int key);

int main() {
	
	int key;
	int result = 0;

	int arr[12] = { 5,7,15,28,29,31,39,58,68,70,90,110 };
	int len = sizeof(arr) / sizeof(arr[1]);

	for (int i = 0; i < len; i++) {
		printf("arr[%d] : %d\n", i, arr[i]);
	}

	printf("key를 입력하세요:");
	scanf("%d",&key);

	result = bin_search(arr, len, key);

	if (result == -1) {
		printf("not found key value");
	}
	else {
		printf("found %d", result);
	}

	return 0;
}

int bin_search(const int ary[], int len, int key) {
	
	int pl = 0;
	int pr = len - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;

		if (ary[pc] == key)
			return pc;

		else if (ary[pc] < key) {
			pl = pc + 1;
		}
		else if (ary[pc] > key) {
			pr = pc - 1;
		}

	}while (pl <= pr);	//pl값이 pr 보다 크면 종료

	return -1;

}