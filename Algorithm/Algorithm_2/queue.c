#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {

	int max;
	int num;
	int front;
	int rear;
	int* que;

}IntQueue;

void Initialize(IntQueue* q, int max);
int Enque(IntQueue* q, int x);
int Deque(IntQueue* q);
int Peek(IntQueue* q);
void Print(IntQueue* q);
void Clear(IntQueue* q);
void Terminate(IntQueue* q);						//스택 종료 메모리 해제 free();
int Capacity(IntQueue* q);							//스택 용량 확인
int Size(IntQueue* q);									//스택안의 데이터 개수
int IsEmpty(IntQueue* q);							//스택이 비어있는지 확인
int IsFull(IntQueue* q);									//스택이 가득 찼는지 검사
int Search(IntQueue* q, int x);						//임의값 검사

int main() {

	int result = 0;
	int menu;
	int x = 0;

	IntQueue q;
	printf("make a Queue Succes\n");
	printf("---------------------------------------------\n");
	Initialize(&q, 3);

	while (1) {
		printf("(1)Enque (2)Deque (3)Peek (4)Print\n");
		printf("(5)Clear (6)Terminate (7)Capacity (8)Size\n");
		printf("(9)IsEmpty (10)IsFull (11)Search (0)END (99)CLEAR Terminal\n");
		printf("---------------------------------------------\n");
		printf("select menu: ");
		scanf("%d", &menu);
		printf("---------------------------------------------\n");
		if (menu == 0)
			break;

		switch (menu) {
		case 1:
			printf("input value: ");
			scanf("%d", &x);
			result = Enque(&q, x);
			if (result == -1) {
				puts("Queue Fail");
				printf("---------------------------------------------\n");
			}
			else {
				printf("value %d is Enque Succes\n", x);
				printf("---------------------------------------------\n");
			}
			break;

		case 2:
			result = Deque(&q);
			if (result == -1) {
				puts("Deque Fail Enque is Empty");
				printf("---------------------------------------------\n");
			}
			else {
				printf("Deque value %d\n", result);
				printf("---------------------------------------------\n");

			}
			break;

		case 3:
			result = Peek(&q);
			if (result == -1) {
				puts("Empty Queue");
				printf("---------------------------------------------\n");
			}
			else {
				printf("%d\n", result);
				printf("---------------------------------------------\n");
			}
			break;

		case 4:
			Print(&q);
			printf("---------------------------------------------\n");
			break;

		case 5:
			Clear(&q);
			printf("Clear Queue");
			printf("---------------------------------------------\n");
			break;

		case 6:
			Terminate(&q);
			printf("Terminate Queue");
			printf("---------------------------------------------\n");
			break;

		case 7:
			result = Capacity(&q);
			printf("Capacity reminig is %d\n", result);
			printf("---------------------------------------------\n");
			break;
		
		case 8:
			result = Size(&q);
			printf("Size is %d\n", result);
			printf("---------------------------------------------\n");
			break;

		case 9:
			result = IsEmpty(&q);
			if (result == -1) {
				printf("Queue is not Empty\n");
				printf("---------------------------------------------\n");
			}
			else {
				printf("Queue is Empty\n");
				printf("---------------------------------------------\n");
			}
			break;

		case 10:
			result = IsFull(&q);
			if (result == -1) {
				printf("Queue is not Full\n");
				printf("---------------------------------------------\n");
			}
			else {
				printf("Queue is Full\n");
				printf("---------------------------------------------\n");
			}
			break;

		case 11:
			printf("what want you find?: ");
			scanf("%d",&x);
			result = Search(&q, x);
			if (result == -1){
				printf("%d is not exist in Queue\n", x);
				printf("---------------------------------------------\n");
			}
			else{
				printf("key is %d index\n",result);
				printf("---------------------------------------------\n");
			}
			break;

		case 99:
			system("CLS");
			break;

		}

	}
	return 0;
}

void Initialize(IntQueue* q, int max) {
	q->num = 0;
	q->front = 0;
	q->rear = 0;

	q->que = calloc(max, sizeof(q->que[0]));
	q->max = max;
}

int Enque(IntQueue* q, int x){
	if (q->num >= q->max)
		return -1;

	q->num++;
	//q->rear이 공백을 가르키고 있다. 값을 저장받기 위해
	q->que[q->rear] = x;
	q->rear++;

	//max 칸에 값을 저장했으면 0번 인덱스부터 저장
	if (q->rear == q->max)
		q->rear = 0;
}

int Deque(IntQueue* q) {
	if (q->num == 0)
		return -1;

	q->num--;
	int x = q->que[q->front];

	q->front++;

	if (q->front == q->max)
		q->front = 0;

	return x;
}

int Peek(IntQueue* q) {
	if (q->rear == 0)
		return -1;
	else
		return q->que[q->rear-1];
}

void Print(IntQueue* q){

	int temp = q->front;
	int temp2 = 0;

	for (int i = 0; i < q->num; i++) {
		if (temp != q->max) {
			printf("index %d is %d | ", i, q->que[temp++]);
		}
		else
			printf("index %d is %d | ", i, q->que[temp2++]);
	}
	puts("");
	
}

void Clear(IntQueue* q){
	q->num = 0;
}

void Terminate(IntQueue* q){
	if (q->que != NULL)
		free(q->que);
	q->max = 0;
	q->num = 0;
}

int Capacity(IntQueue* q){
	return q->max - q->num;
}

int Size(IntQueue* q){
	return q->num;
}

int IsEmpty(IntQueue* q){
	return q->num <= 0;
}

int IsFull(IntQueue* q){
	if (q->num == q->max)
		return 0;
	else
		return -1;
}

int Search(IntQueue* q, int x){
	
	int temp = q->front;
	int temp2 = 0;

	for (int i = 0; i < q->num; i++) {
		if (temp != q->max) {
			if (x == q->que[temp++])
				return i;
		}
		else{
			if (x == q->que[temp2++])
				return i;
		}
	}
	return 100;

	/*int temp = 0;
	int result;

	for (int i = 0; i < q->num; i++) {
		if (q->front != q->max) {
			if(q->que[q->front] == x)
				return i;
		}
		else
			if (q->que[temp++] == x)
				return i;
	}

	return 100;*/
}
