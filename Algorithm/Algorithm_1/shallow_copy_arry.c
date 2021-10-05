#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void init(int x[], int len);
void print_arr(char c, int arr[], int len);
void copy(int* x, int y[], int len);
void arr_reverse(int y[], int  len);

int main() {
	int* x;
	int* y;
	int len;

	printf("��� �����ұ��?");
	scanf("%d", &len);

	x = calloc(len, sizeof(int));
	y = calloc(len, sizeof(int));
	
	//init array x[]
	init(x, len);

	printf("original array x[]\n");
	print_arr('x', x, len);
	//for (int i = 0; i < len; i++) {
	//	printf("x[%d] = %d\n",i ,x[i]);
	//}
	
	//copy x[] to y[]
	copy(x, y, len);

	printf("before flipping a array y[]\n");

	for (int i = 0; i < len; i++) {
		printf("x[%d] = %d\n",i ,x[i]);
	}

	//reverse y[]
	arr_reverse(y, len);

	printf("after flipping a array y[]\n");

	for (int i = 0; i < len; i++) {
		printf("y[%d] = %d\n", i, y[i]);
	}

	free(x);
	free(y);

	return 0;
}




void arr_reverse(int y[], int len) {

	int temp = 0;
	//������ �ε��� ��ȣ�� 7�� �ƴ� 6�̴�. 0~6����
	/*printf("%d",arr[len-1]);*/
	for (int i = 0; i < len/2 ; i++) {
		temp = y[i];
		y[i] = y[(len - 1) - i];
		y[(len - 1) - i] = temp;
	}
}

//�迭 x�� �� ����
void init(int x[], int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		x[i] = rand() % 100 + 1;
	}
}

void print_arr(char c, int arr[], int len){
	for (int i = 0; i < len; i++) {
		printf("%c[%d] = %d\n",c , i, arr[i]);
		//printf("x[%d] = %d\n",i ,x[i]);
	}
}


void copy(int* x, int y[], int len){
	for (int i = 0; i < len; i++) {
		y[i] = x[i];
	}
}
