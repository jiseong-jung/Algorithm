#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//배열을 읽기전용으로만 하기 위해 const를 사용한다.
int Arrmax(const int arr[], int len);

int main() {
	
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		arr[i] = (int)rand() % 100 + 100;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	int result = Arrmax(arr, len);
	printf("길이 %d\n", len);
	printf("가장 큰 수는 %d\n", result);
}

int  Arrmax(const int arr[], int len)
{
	int check = 0;
	int max = arr[0];

	for (int i = 0; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
			check = i;
		}
	}
	printf("double check %d\n", arr[check]);

	return max;
}
