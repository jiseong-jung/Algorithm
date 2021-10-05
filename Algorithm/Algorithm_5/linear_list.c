#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int mem_no;
	char name[10];
	char phone[15];
	int max;
}Person;

Person data[] = {
		{11, "jung", "01088055636"},
		{25, "kim", "01041111111"},
		{31, "park", "01054386742"},
		{50, "ham", "01084074884"},
		{54, "mon", "01045374444"},
		{60, "jun", "01012341234"},
		{0, "",""}
};

void add(Person data[], int len, int count);
void del(Person data[], int len,int x);
void ins(Person data[], int len, int x, int count);
void print(Person data[], int len);




int main() {

	int menu;
	int x;
	
	int len = sizeof(data) / sizeof(data[0]);
	printf("총 회원 수%d\n",len);
	printf("----------------------------------------------\n");

	while (1) {
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (data[i].mem_no != 0)
				count++;
		}

		printf("현재 등록된 회원 수는 %d\n", count);

		puts("select menu");
		puts("1.Add, 2.Delete, 3.Insert 4.Print (0)END");
		printf("----------------------------------------------\n");
		printf(">");
		scanf("%d", &menu);

		if (menu == 0)
			break;

		switch (menu)
		{
		case 1:
			printf("회원 추가\n");
			add(data, len, count);
			break;
		case 2:
			printf("삭제하고 싶은 회원번호를 입력하세요 :");
			scanf("%d", &x);
			del(data, len, x);
			break;

		case 3:
			printf("수정하고 싶은 index번호를 입력하세요 : ");
			scanf("%d", &x);
			ins(data, len, x, count);
			break;

		case 4:
			print(data, len);
			break;
		}
	}
	return 0;
}

void add(Person data[], int len, int count) {
	int i;

	if (len == count) {
		printf("Memory is Full\n");
		return;
	}


	for (i = 0; i <= len; i++) {
		if (data[i].mem_no == 0) {
		
			printf("회원 번호를 입력하세요: ");
			scanf("%d",&data[i].mem_no);
			printf("이름을 입력하세요: ");
			scanf("%s", &data[i].name);
			printf("전화번호를 입력하세요: ");
			scanf("%s", &data[i].phone);
			break;
		}
	}
	printf("----------------------------------------------\n");
	printf("추가된 회원정보는\n");
	printf("%d\n",data[i].mem_no);
	printf("%s\n", data[i].name);
	printf("%s\n", data[i].phone);
	printf("----------------------------------------------\n");
}

void del(Person data[], int len, int x){

	for (int i = 0; i < len; i++) {
		if (data[i].mem_no == x) {
			data[i].mem_no = 0;
			strcpy(data[i].name, " ");
			strcpy(data[i].phone, " ");

			for (int j = i ; j < len; j++) {
				data[j] = data[j + 1];
			}

		}
	}
}

void ins(Person data[], int len, int x, int count) {

	if (len == count) {
		printf("Memory is Full\n");
		return;
	}

	else {

		for (int i = len - 0; i >= x; i--) {
			data[i] = data[i - 1];
		}

		printf("회원 번호를 입력하세요: ");
		scanf("%d", &data[x].mem_no);
		printf("이름을 입력하세요: ");
		scanf("%s", &data[x].name);
		printf("전화번호를 입력하세요: ");
		scanf("%s", &data[x].phone);

		printf("----------------------------------------------\n");
		printf("추가된 회원정보는\n");
		printf("%d\n", data[x].mem_no);
		printf("%s\n", data[x].name);
		printf("%s\n", data[x].phone);
		printf("----------------------------------------------\n");
	}

	

}

void print(Person data[], int len) {

	for (int i = 0; i < len; i++) {
		printf("data[%d] = %d", i, data[i].mem_no);
		printf(" %s", data[i].name);
		printf(" %s\n", data[i].phone);
		
	}
	printf("----------------------------------------------\n");
}
