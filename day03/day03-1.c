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
	printf("���ڸ� �Է��ϼ���");
	scanf_s("%d", &input);
	int res = sosu(input);
	printf("%d\n", res);
	
	return 0;
}