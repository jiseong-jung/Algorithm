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
	
	Physical p[] = { {"박현규", 162, 0.7}, {"함진아", 173, 0.7},
							{"최윤미", 175, 2.0}, {"홍연의", 171, 1.2},
							{"이수진", 168, 0.4}, {"김영준", 174, 1.2},
							{"박용규", 169, 0.8} };

	int len = sizeof(p) / sizeof(p[0]);
	puts(" 신체 검사 표");
	puts("이름\n	키		시력");
	puts("------------------------------------------------------------");

	for (int i = 0; i < len; i++) {
		printf("%s \t %4d 평균 키: %5.1f cm\n", p[i].name, p[i].height, p[i].vision);
	}
	printf("\n평균 키: %5.1f cm\n", ave_height(p,len));

	vision_count(p, len);

	return 0;
}

