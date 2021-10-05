//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[20];
	int height;
	float vision;
}Physical;

void vision_count(const Physical dat[], int len) {

	for (int i = 1; i <= 20; i++) {
		float a = i * 0.1;
		printf("%.1f = ",a);
		for (int j = 0; j < len; j++){
			if(a == dat[j].vision)
				printf("*");
		}
		printf("\n");
	}

}

float ave_height(const Physical dat[], int len) {
	double sum = 0;

	for (int i = 0; i < len; i++) {
		sum += dat[i].height;
	}

	return (float)sum / len;
}

int main() {
	
	Physical p[] = { {"������", 162, 0.7}, {"������", 173, 0.7},
							{"������", 175, 2.0}, {"ȫ����", 171, 1.2},
							{"�̼���", 168, 0.4}, {"�迵��", 174, 1.2},
							{"�ڿ��", 169, 0.8} };

	int len = sizeof(p) / sizeof(p[0]);
	puts(" ��ü �˻� ǥ");
	puts("�̸�\n	Ű		�÷�");
	puts("------------------------------------------------------------");

	for (int i = 0; i < len; i++) {
		printf("%s \t %4d ��� Ű: %5.1f cm\n", p[i].name, p[i].height, p[i].vision);
	}
	printf("\n��� Ű: %5.1f cm\n", ave_height(p,len));

	vision_count(p, len);

	return 0;
}

