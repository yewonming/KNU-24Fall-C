#include <stdio.h>
int main() {

	int Num = 0;
	scanf_s("%d", &Num);

	printf("%d층 피라미드\n", Num);
	
	for (int i = 1;i <= Num;i++){

		for (int h = i;h <= Num - 1;h++) {
			printf(" ");
		}
		for (int j = 0;j < 2*i-1;j++) {
			printf("*");
			}
		printf("\n");
	}
	return 0;
}