#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int int_cmp(const int* a, const int* b);

int main() {
	int key;
	int* p;
	int ary[8] = { 15, 18, 23, 39, 57, 68, 72 };
	int len = sizeof(ary) / sizeof(ary[0]);

	puts("이진 방식");

	for (int i = 0; i < len; i++) {
		printf("ary[%d]: %d ", i, ary[i]);
	}
	puts("\n");

	printf("검색 값: ");
	scanf("%d", &key);

	//p = bsearch(&key,
	//	ary,
	//	len,
	//	sizeof(ary[0]),
	//	// 반환타입 int형 포인터, 매개변수 2개
	//	(int(*	)(const void*, const void*))int_cmp);

	p = bsearch(&key,
		ary,
		len,
		sizeof(ary[0]),
		// 반환타입 int형 포인터, 매개변수 2개
		int_cmp);

	if (p == NULL)
		printf("검색 실패");
	else
		printf("%d는 ary[%d]에 있습니다.\n", key, (int)(p-ary));

	return 0;

}

int int_cmp(const int* a, const int* b){
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}
