#include<stdio.h>

int pos[8];
int flag_a[8];
int flag_b[15];
int flag_c[15];

void set(int i);
void print(void);

int main() {
	
	for (int i = 0; i < sizeof(flag_a) / sizeof(flag_a[0]); i++) {
		flag_a[i] = 0;
	}

	printf("%d", sizeof(flag_a) / sizeof(flag_a[0]));

	set(0);

	return 0;
}	

//flag use 8*7*6*5*4*3*2*1
void set(int i) {

	for (int j = 0; j < 8; j++) {

		if (!flag_a[j]) {	//flag 값이 0이 아닐때
			pos[i] = j;
			if (i == 7)
				print();

			else {
				flag_a[j] = 1;
				set(i + 1);
				flag_a[j] = 0;
			}

		}
	}
}


//hard coding 8*8*8*8*8*8*8*8
//void set(int i) {
//	for(int j=0; j< 8; j++){
//		pos[i] = j;
//		if (i == 7)
//			print();
//		else
//			set(i + 1);
//	}
//}

//void print() {
//	for (int i = 0; i < 8; i++) {
//		printf("%2d", pos[i]);
//	}
//	putchar('\n');
//}

void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%s",  j== pos[i] ? "□": "■");
		}
		putchar('\n');
	}
}