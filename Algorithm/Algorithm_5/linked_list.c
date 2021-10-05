#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int no;
	char name[20];
} Member;

typedef struct _node {
	Member  data;
	struct _node* next;
}Node;

Node* AllocNode(void) {
	return calloc(1, sizeof(Node));
}

void SetNode(Node* n, const Member* x, const Node* next) {
	n->data = *x;
	n->next = next;
}


typedef struct {
	Node* head;
	Node* crnt;
}List;

void Initialize(List* list) {
	list->head = NULL;
	list->crnt = NULL;
}

void InsertRear(List* list, const Member* x);
void InsertFront(List* list, const Member* x);

Node* Search(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Node* ptr = list->head;
	while (ptr != NULL) {
		if (compare(x, &ptr->data) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}



void RemoveFront(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;
		free(list->head);
		list->head = list->crnt = ptr;
	}
}

void RemoveRear(List* list) {
	if (list->head != NULL) {
		if ((list->head)->next == NULL)
			RemoveFront(list);			//list�� �Ӹ��� �����ϰ� null���ϰ�� �����Ұ��� head�� ���̴�.
		else {
			Node* ptr = list->head;
			Node* pre = NULL;

			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = NULL;
			free(ptr);
			list->crnt = pre;
		}
	
	}
	
}

void RemoveCurrent(List* list) {
	if (list->head != NULL) {
		if (list->crnt == list->head)
			RemoveFront(list);
		else {
			Node* ptr = list->head;
			while (ptr->next != list->crnt)
				ptr = ptr->next;

			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear(List* list) {
	while (list->head != NULL)
		RemoveFront(list);
	list->crnt = NULL;
}

void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

void PrintLnMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}

void PrintCurrent(const List* list) {
	if (list->crnt == NULL)
		printf("������ ��尡 �����ϴ�.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List* list) {
	PrintCurrent(list);
	putchar('\n');
}

void Print(const List* list) {
	if (list->head == NULL)
		puts("node�� �����ϴ�.");
	else {
		Node* ptr = list->head;
		puts("[��� ����]");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void Terminatae(List* list) {
	Clear(list);
}

int NumberCmp(const Member* x, const Member* y) {
	if (x->no < y->no)
		return -1;
	else if (x->no > y->no)
		return 1;
	else
		return 0;
}

int NameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
}

int SelectMenu(void) {
	int num = 0;

	puts("\n���ϴ� �޴��� �����ϼ���.");
	puts("(1) �Ӹ��� ��带 ����\t (2) ������ ��带 ����\t(3) �Ӹ� ��带 ����");
	puts("(4) ���� ��带 ����\t (5) ���� ��带 ���\t (6) ������ ��带 ����");
	puts("(7) ��ȣ�� �˻�\t (8) �̸����� �˻�\t (9)��� ��带 ���");
	puts("(10)��� ��带 ����\t (0) ����\t");
	scanf("%d",&num);

	return num;
}


int main() {
	int menu = 0;
	int s=0;
	List list;
	Member x;
	Node* y = NULL;

	Initialize(&list);

	do {
		
		menu = SelectMenu();

		switch (menu) {
		case 1:
			puts("�Ӹ��� �����ϴ� �����͸� �Է��ϼ���");
			printf("��ȣ: ");
			scanf("%d",&x.no);
			printf("�̸�: ");
			scanf("%s", x.name);
			InsertFront(&list, &x);
			break;

		case 2:
			puts("������ �����ϴ� �����͸� �Է��ϼ���");
			printf("��ȣ: ");
			scanf("%d",&x.no);
			printf("�̸�: ");
			scanf("%s", x.name);
			InsertRear(&list, &x);
			break;

		case 3:
			RemoveFront(&list);
			break;
		case 4:
			RemoveRear(&list);
			break;
		case 5:
			PrintCurrent(&list);
			break;
		case 6:
			printf("������ ��带 ����\n :");
			scanf("%d",&s);
			Search(&list, &x, s);
			break;
		
		case 7:
			printf("��ȣ�� �˻�");
			scanf("%d",&x.no);
			/*scanf("%d", &y->data.no);
			y = Search(&list, &x, (&x, &y));*/

			Search(&list, &x, NumberCmp);
			PrintCurrent(&list);
			/*printf("%s",y->data.name);*/
			break;
		/*case 8:
		* printf("�̸����� �˻�");
			Print(&list, &x);
			break;*/
		case 9:
			Print(&list);
			break;
		case 10:
			Terminatae(&list);
			break;

		}
	} while (menu != 0);

	Terminatae(&list);

	return 0;

}



void InsertFront(List* list, const Member* x) {
	Node* ptr = list->head;

	list->head = list->crnt = AllocNode();

	SetNode(list->head, x, ptr);
}

void InsertRear(List* list, const Member* x) {
	if (list->head == NULL)
		InsertFront(list, x);
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}