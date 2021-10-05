#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int bin_search(const int ary[], int len, int key);

int main() {

	int key;
	int result = 0;

	//int arr[11] = {1,3,5,7,7,7,7,8,8,9,9 };
	int arr[11] = { 1,1,1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[1]);

	for (int i = 0; i < len; i++) {
		printf("arr[%d] : %d\n", i, arr[i]);
	}

	printf("key�� �Է��ϼ���:");
	scanf("%d", &key);

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
	//return ������ ���̱� ���� ��ȯ�� ����
	int temp = -1;


	do {
		pc = (pl + pr) / 2;

		if (ary[pc] == key){
			temp = pc;
			
			//while(pc > p1 && ary[pc - 1] == key)
			//pc--;
			while (ary[pc] == ary[pc]) {
				if (pc == 0) {
					temp = 0;
					break;
				}
				temp = pc - 1;
				pc--;
			}
			/*return temp;*/
			break;
		}

		//key�� pc���� Ŭ ���
		else if (ary[pc] < key) {
			pl = pc + 1;
		}

		//key�� pc���� ���� ���
		else if (ary[pc] > key) {
			pr = pc - 1;
		}


	} while (pl <= pr);	//pl���� pr ���� ũ�� ����

	return temp;

}