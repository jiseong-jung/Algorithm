#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//void card_convr(unsigned number, int n, char arr[]);

int card_convr(unsigned number, int n, char arr[]) {

	//16������ ����ϱ� ���� dchar�迭
	//�ƽ�Ű�ڵ�� �޾���
	char dchar[] = "0123456789ABCDEF";
	int digit = 0;

	while (number != 0) {
		//arr[digit++] = number % n;
		arr[digit++] = dchar[number % n];
		number = number / n;
	}

	/*printf(" %d�����δ� ", n);
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

	printf("10������ ���� ��ȯ �մϴ�.");
	do {
		printf("���� �ƴ� ���� ������ �Է��Ͽ� �ּ���\n	>");
		scanf("%d", &input);
	} while (input < 0);

	while (1) {
		printf("� ������ ��ȯ�ұ��? (2,8,16)\n>	");
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

	printf(" %d�����δ� ", pick);
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
//	printf(" %d�����δ� ", n);
//	for (int i = digit; i >0; i--) {
//		printf("%d ", arr[i-1]);
//	}
//
//}