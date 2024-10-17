#include <stdio.h>
#include <string.h>

void swap(char* a) {
	char newspace;
	char* start = a;
	char* end = a + strlen(a) - 1;
	for (int i = 0;i < (strlen(a) / 2);i++) {
		newspace = *start;
		*start = *end;
		*end = newspace;

		start++;
		end--;
	}
}
int main() {
	char eng[100];
	printf("문자열을 입력하세요:");
	scanf_s("%s", eng, 100);

	swap(eng);

	printf("%s", eng);

	return 0;
}
