#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max 10

int gcd(int a, int b);

int main() {

	int a, b;
	int result = 0;

	printf("Find a GCD\n");
	printf("first value: ");
	scanf("%d", &a);
	printf("second value: ");
	scanf("%d", &b);

	result = gcd(a, b);
	printf("result is : %d\n", result);


	return 0;
}

int gcd(int a, int b) {

	int arr1[max] = { 0 };
	int arr2[max] = { 0 };
	//int arr1 = calloc(a, sizeof(int));

	int a1=0;
	int b1=0;
	int result = 0;

	//a의 공약수 구하기
	for (int i = 1; i <= a; i++) {
		if (a % i == 0)
			arr1[a1++] = i;
	}

	//b의 공약수 구하기
	for (int i = 1; i <= b; i++) {
		if (b % i == 0)
			arr2[b1++] = i;
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (arr1[i] == arr2[j]) {
				if (result < arr1[i])
					result = arr1[i];
			}
		}
	}

		return result;
}