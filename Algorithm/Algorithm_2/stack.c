#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int max;		//stack ��ü �뷮
	int ptr;			//���ÿ� �׿� �ִ� ������ ���� ��ġ (������ ����)
	int* stk;		//������ �ּ� ��

}IntStack;

void Initialize(IntStack* s, int max);		//���� �ʱ�ȭ
int Push(IntStack* s, int x);					//���� �� �ֱ�
int Pop(IntStack* s);								//���� �� ������
int Peek(IntStack* s);							//���� �� ���� �� ���
void Clear(IntStack* s);							//���� ����
void Print(IntStack* s);							//���� ���
void Terminate(IntStack* s);					//���� ���� �޸� ���� free();
int Capacity(IntStack* s);						//���� �뷮 Ȯ��
int Size(IntStack* s);								//���þ��� ������ ����
int IsEmpty(IntStack* s);					//������ ����ִ��� Ȯ��
int IsFull(IntStack* s);							//������ ���� á���� �˻�
int Search(IntStack* s, int x);						//���ǰ� �˻�

int main() {

	IntStack s;
	Initialize(&s, 2);
	printf("stack make sucees\n");

	while (1) {
		int menu, x;
		int result;

		/*printf("(0)end  (1)push (2)pop (3)peek (4)print (5)clear\n");
		printf("(6)capacity (7)size (8)isempty (9)isfull (10)search\n");
		printf("select menu :");*/

		printf("(1)Enque (2)Deque (3)Peek (4)Print\n");
		printf("(5)Clear (6)Terminate (7)Capacity (8)Size\n");
		printf("(9)IsEmpty (10)IsFull (11)Search (0)END");

		scanf("%d", &menu);

		if (menu == 0) {
			break;
		}

		switch (menu) {
		case 1:
			printf("data input :");
			scanf("%d", &x);
			result = Push(&s, x);
			
			if (result == -1)
				printf("stack is full\n");
			break;

		case 2:
			result = Pop(&s);
			if (result == -1)
				printf("pop fail\n");
			else
				printf("pop data is : %d\n", result);
			break;

		case 3:
			result = Peek(&s);

			if (result == -1)
				printf("peek fail\n");
			else
				printf("peek data is : %d\n", result);
			break;

		case 4:
			Print(&s);
			break;

		case 5:
			Clear(&s);
			printf("stack clear\n");
			break;
		
		
		case 6:
			result = Capacity(&s);
			printf("capacity remainig is : %d\n", result);
			break;

		case 7:
			result = Size(&s);
			printf("stack number is : %d\n", result);
			break;
		
		case 8:
			result = IsEmpty(&s);
			if (result == -1)
				printf("stack is not empty\n");
			else
				printf("stack is empty\n");
			break;

		case 9:
			result = IsFull(&s);
			if (result == -1)
				printf("stack is not full\n");
			else
				printf("stack is full\n");
			break;

		case 10:
			printf("key value : ");
			scanf("%d", &x);
			result = Search(&s, x);
			if (result == -1)
				printf("not found key value\n");
			else
				printf("value index is %d\n",result);
			break;

		}//end of  switch
		
	}

	Terminate(&s);

	return 0;
}

//�ʱ�ȭ
void Initialize(IntStack* s, int max) {

	s->stk = calloc(max, sizeof(s->stk[0]));
	s->ptr = 0;
	s->max = max;
}

int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)
		return -1;

	s->stk[s->ptr] = x;
	s->ptr++;

	return 0;
}

int Pop(IntStack* s) {
	if (s->ptr <= 0)
		return -1;

	int x = s->stk[s->ptr];
	s->ptr--;

	return x;
}

//ptr�� ���� ������ �ʿ䰡 ����.
int Peek(IntStack* s) {
	if (s->ptr <= 0)
		return -1;
	int x = s->stk[s->ptr - 1];

	return x;
}

void Clear(IntStack* s) {
	s->ptr = 0;
}

void Print(IntStack* s) {
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);
	printf("\n");
}

void Terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = 0;
	s->ptr = 0;
}

int Capacity(IntStack* s){

	return s->max - s->ptr;
}

int Size(IntStack* s){
	
	return s->ptr;
}

int IsEmpty(IntStack* s){
	int result = -1;

	if (s->ptr != 0)
		result = -1;
	else
		result = 0;

	return result;
}

int IsFull(IntStack* s) {
	int result;

	if (s->ptr == s->max)
		result = 0;
	else
		result = -1;

	return result;
}

int Search(IntStack* s, int x){

	for (int i = 0; i < s->ptr; i++) {
		if (x == s->stk[i])
			return i;
	}

	return -1;
}
