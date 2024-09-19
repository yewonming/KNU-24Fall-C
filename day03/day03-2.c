#include <stdio.h>
int factorial(int num) {
	if (num > 1) {
		int result;
		result = num * factorial(num - 1);
		return result;
	}

	return 1;
	
}

int main(void) {
	int num;
	scanf_s("%d", &num);
	printf("%d!=%d",num,factorial(num));
	return 0;
}