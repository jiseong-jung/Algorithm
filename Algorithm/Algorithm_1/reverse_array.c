#include<stdio.h>

void arry_reverse(int arr[], int len);

int main() {

	int arr[] = { 22, 57, 11, 32, 91, 68, 70, 90};
	int len = sizeof(arr) / sizeof(arr[0]);

	//before
	puts("before reverse");
	for (int i = 0; i < len; i++) {
		printf("%d��° ��: %d\n", i, arr[i]);
	}

	arry_reverse(arr, len);

	//after
	puts("");
	puts("after reverse");
	for (int i = 0; i < len; i++) {
		printf("%d��° ��: %d\n", i, arr[i]);
	}

	return 0;
}

void arry_reverse(int arr[], int len) {

	int temp =0;
	//������ �ε��� ��ȣ�� 7�� �ƴ� 6�̴�. 0~6����
	/*printf("%d",arr[len-1]);*/
	for (int i = 0; i < (len)/2; i++) {
		temp = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-1 - i] = temp;
	
	}

}