#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void partition(int a[], int n) {
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];		//��� ���߽� ���

	while (pl <= pr) {

		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			int temp = a[pl];
			a[pl] = a[pr];
			a[pr] = temp;

			pl++;
			pr--;
		}
	}

		printf("�ǹ��� ���� %d �Դϴ�.\n", x );
		printf("�ǹ� ������ �׷�\n");
		for (int i = 0; i <= pl - 1; i++)
			printf("%d ",a[i]);
		putchar('\n');

		if (pl > pr + 1) {
			printf("�ǹ��� ��ġ�ϴ� �׷�\n");
			for (int i = pr + 1; i <= pl -  1; i++)
				printf("%d ", a[i]);
			putchar('\n');
		}
		printf("�ǹ� �̻��� �׷�\n");
		for (int i = pr + 1; i < n; i++)
			printf("%d ",a[i]);
		putchar('\n');
	}



int main() {
	int nx;
	int* x;

	srand(time(NULL));

	puts("�迭�� ��Ҹ� �����ϴ�.");
	printf("����� ���� :");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(x[0]));


	for (int i = 0; i < nx; i++) {
		x[i] = (int)rand() % 100+1;
		printf("%d\n", x[i]);
	}

	partition(x, nx);

	//free(x);

	return 0;

}