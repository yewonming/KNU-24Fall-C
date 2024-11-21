#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {

	int a, b, c = 0;

	printf("이차방정식을 입력하세요(ax^2+bx+c)");
	scanf_s("%d, %d, %d", &a, &b, &c);

	if ((pow(b, 2) - 4 * a * c) < 0) {
		printf("허근입니다");
	}else if((pow(b, 2) - 4 * a * c) == 0){
		printf("%.2f", ((-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a));
	}
	else {
		printf("%.2f", ((-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a));
		printf("%.2f", ((-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a));
	}
}




