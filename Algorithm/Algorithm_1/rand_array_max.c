#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�迭�� �б��������θ� �ϱ� ���� const�� ����Ѵ�.
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
	printf("���� %d\n", len);
	printf("���� ū ���� %d\n", result);
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
