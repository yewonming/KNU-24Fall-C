#include <stdio.h>
int main() {
	int input;
	double output = 0.0;
	printf("원하는 기능을 입력하시오");
	printf("1.더하기 2. 빼기 3. 곱하기 4. 나누기");
	printf("기능: ");
	scanf_s("%d", &input);

	double num1, num2;
	printf("숫자 1을 입력하세요:");
	scanf_s("%lf", &num1);

	printf("숫자 2를 입력하세요: ");
	scanf_s("%lf", &num2);

	if (input == 1) {
		output = num1 + num2;
		printf("%lf + %lf = %lf", num1, num2, output);
	}
	else if (input == 2) {
		output = num1 - num2;
		printf("%lf- %lf= %lf", num1, num2, output);
	}
	else if (input == 3) {
		output = num1 * num2;
		printf("%lf * %lf = %lf", num1, num2, output);
	}
	else {
		output = num1 / num2;
		printf("%lf / %lf = %lf", num1, num2, output);
	}
	return 0;
}