#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void nrpira(int n) {
	/*for (int i = n; n>=0;  n--){
		

		for (int j = 0;  j <( n * 2 - 1 ); j++ ) {
			printf("%d",n);
		}

		printf("\n");
	}*/
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i-1; j++)
			printf("#");

		for (int j = 1; j <= (n-i)*2 + 1; j++) {
			printf("%d",i%10);
		}
		printf("\n");
	}

}

int main() {

	int n;
	puts("피라미드를 출력합니다.");
	do {
		printf("단수 :");
		scanf("%d", &n);
	} while (n <= 0);

	nrpira(n);

	return 0;
}