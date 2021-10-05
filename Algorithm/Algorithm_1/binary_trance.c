#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//void card_convr(unsigned number, int n, char arr[]);

int card_convr(unsigned number, int n, char arr[]) {

	//16진수로 출력하기 위한 dchar배열
	//아스키코드로 받아줌
	char dchar[] = "0123456789ABCDEF";
	int digit = 0;

	while (number != 0) {
		//arr[digit++] = number % n;
		arr[digit++] = dchar[number % n];
		number = number / n;
	}

	/*printf(" %d진수로는 ", n);
	for (int i = digit; i >0; i--) {
		printf("%c ", arr[i - 1]);
	}*/
	return digit;
}

int main() {

	int input = 0;
	int pick = 0;
	char arr[100];
	int digit;

	printf("10진수를 진수 변환 합니다.");
	do {
		printf("음이 아닌 양의 정수를 입력하여 주세요\n	>");
		scanf("%d", &input);
	} while (input < 0);

	while (1) {
		printf("어떤 진수로 변환할까요? (2,8,16)\n>	");
		scanf("%d", &pick);
		if (pick == 2) {
			digit = card_convr(input, pick, arr);
			break;
		}
		else if (pick == 8) {
			digit = card_convr(input, pick, arr);
			break;
		}
		else if (pick == 16) {
			digit = card_convr(input, pick, arr);
			break;
		}
	}

	printf(" %d진수로는 ", pick);
	for (int i = digit- 1; i >= 0; i--) {
		printf("%c ", arr[i]);
	}

	return 0;
}
//
//void card_convr(unsigned number, int n, char arr[]) {
//
//	int digit = 0;
//	
//	while (number != 0) {
//		arr[digit++] = number % n;
//		number = number / n;
//	}
//
//	/*for(int i=0; i<digit; i++){
//		printf("%d ",arr[i]);
//	}
//	printf("\n");*/
//
//	printf(" %d진수로는 ", n);
//	for (int i = digit; i >0; i--) {
//		printf("%d ", arr[i-1]);
//	}
//
//}