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
		{"�迵��", 172, 67}, {"������", 185, 76}, {"�̼���", 176, 52},
		{"������", 168, 55}, {"������", 165, 51}, {"ȫ����", 172, 84}
	};

	int nx = sizeof(x) / sizeof(x[0]);
	Person temp;
	Person* p;

	puts("�̸����� �˻��մϴ�.");
	printf("�̸��� �Է��ϼ���: ");
	scanf("%s", temp.name);

	p = p = bsearch(&temp,
		x,
		nx,
		sizeof(x[0]),
		//key�� �ϳ��� array element�� ����Ű�� �ּҰ��̴�.
		(int(*	)(const void*, const void*))npcmp);

	if (p == NULL)
		printf("�˻� ����");
	else
		printf("%s�� Ű:%dcm , ������: %dkg .\n", p->name, p->height, p->weight);

	return 0;



}

int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}