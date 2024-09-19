#include <stdio.h>
int sosu( int input) {

	for (int b = 2; input > b; b++) {
		if (input % b == 0) {
			return 0;
		}
		return 1;
	}
}

int  main(){

	int input;
	printf("숫자를 입력하세요");
	scanf_s("%d", &input);
	int res = sosu(input);
	printf("%d\n", res);
	
	return 0;
}