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
			RemoveFront(list);			//list의 머리를 제외하고 null값일경우 제거할것은 head의 값이다.
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
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List* list) {
	PrintCurrent(list);
	putchar('\n');
}

void Print(const List* list) {
	if (list->head == NULL)
		puts("node가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("[모두 보기]");
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

	puts("\n원하는 메뉴를 선택하세요.");
	puts("(1) 머리에 노드를 삽입\t (2) 꼬리에 노드를 삽입\t(3) 머리 노드를 삭제");
	puts("(4) 꼬리 노드를 삭제\t (5) 현재 노드를 출력\t (6) 선택한 노드를 삭제");
	puts("(7) 번호를 검색\t (8) 이름으로 검색\t (9)모든 노드를 출력");
	puts("(10)모든 노드를 삭제\t (0) 종료\t");
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
			puts("머리에 삽입하는 데이터를 입력하세요");
			printf("번호: ");
			scanf("%d",&x.no);
			printf("이름: ");
			scanf("%s", x.name);
			InsertFront(&list, &x);
			break;

		case 2:
			puts("꼬리에 삽입하는 데이터를 입력하세요");
			printf("번호: ");
			scanf("%d",&x.no);
			printf("이름: ");
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
			printf("선택한 노드를 삭제\n :");
			scanf("%d",&s);
			Search(&list, &x, s);
			break;
		
		case 7:
			printf("번호로 검색");
			scanf("%d",&x.no);
			/*scanf("%d", &y->data.no);
			y = Search(&list, &x, (&x, &y));*/

			Search(&list, &x, NumberCmp);
			PrintCurrent(&list);
			/*printf("%s",y->data.name);*/
			break;
		/*case 8:
		* printf("이름으로 검색");
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