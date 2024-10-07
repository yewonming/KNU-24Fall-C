#include <stdio.h>

void swap(int *a, int *b) {
	int yewon = *b;
	(*b) = (*a);
	*a = yewon;
}

int main() {
	int a = 10, b = 20;

	printf("a:%d b:%d\n", a, b);
	
	swap(&a, &b);
	printf("a:%d b:%d", a, b);

	
}