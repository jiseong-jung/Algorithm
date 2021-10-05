#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
}Person;

int npcmp(const Person* x, const Person* y);

int main() {

	Person x[] = {
		{"김영준", 172, 67}, {"박현규", 185, 76}, {"이수진", 176, 52},
		{"최윤미", 168, 55}, {"함진아", 165, 51}, {"홍연의", 172, 84}
	};

	int nx = sizeof(x) / sizeof(x[0]);
	Person temp;
	Person* p;

	puts("이름으로 검색합니다.");
	printf("이름을 입력하세요: ");
	scanf("%s", temp.name);

	p = p = bsearch(&temp,
		x,
		nx,
		sizeof(x[0]),
		//key와 하나의 array element를 가리키는 주소값이다.
		(int(*	)(const void*, const void*))npcmp);

	if (p == NULL)
		printf("검색 실패");
	else
		printf("%s는 키:%dcm , 몸무게: %dkg .\n", p->name, p->height, p->weight);

	return 0;



}

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}