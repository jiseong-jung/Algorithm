#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void partition(int a[], int n) {
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];		//��� ���߽� ���
	int left = pl;
	int right = pr;

	printf("----------------------------\n");
	printf("n�� ����%d\n",n);
	printf("x�� ����%d\n",x);
	printf("----------------------------\n");

	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");

	//if()



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
	


	//printf("�ǹ��� ���� %d �Դϴ�.\n", x);
	//printf("�ǹ� ������ �׷�\n");
	//for (int i = 0; i <= pl - 1; i++)
	//	printf("%d ", a[i]);
	//putchar('\n');

	//if (pl > pr + 1) {
	//	printf("�ǹ��� ��ġ�ϴ� �׷�\n");
	//	for (int i = pr + 1; i <= pl - 1; i++)
	//		printf("%d ", a[i]);
	//	putchar('\n');
	//}
	//printf("�ǹ� �̻��� �׷�\n");
	//for (int i = pr + 1; i < n; i++)
	//	printf("%d ", a[i]);
	//putchar('\n');

	
		if (left<pr)
			partition(&a[left],pr+1);
		if(right > pl)
			partition(&a[pl], n - pl);
	

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
		x[i] = (int)rand() % 10 + 1;
		printf("%d\n", x[i]);
	}

	partition(x, nx);

	//free(x);

	return 0;

}