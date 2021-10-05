#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a, b;
	int sum = 0;

	printf("a의 값:");
	scanf("%d", &a);

	printf("b의 값:");
	scanf("%d", &b);

	if (a < b) {
		while (a <= b) {
			sum += a;
			a++;
		}
	}
	else
		while (b <= a) {
			sum += b;
			b++;
		}
	/* if(a<b) min  =a ; max = b;
	*  if(b>a) min  =b ; max = a;
	* 
			for(i = min; i<max; i++){
	*		sum+=i;
	*/

	printf("result: %d",sum);
	return 0;
}