#include <stdio.h>
int main() {
	int input;
	double output = 0.0;
	printf("���ϴ� ����� �Է��Ͻÿ�");
	printf("1.���ϱ� 2. ���� 3. ���ϱ� 4. ������");
	printf("���: ");
	scanf_s("%d", &input);

	double num1, num2;
	printf("���� 1�� �Է��ϼ���:");
	scanf_s("%lf", &num1);

	printf("���� 2�� �Է��ϼ���: ");
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