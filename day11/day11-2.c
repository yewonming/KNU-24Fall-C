#include <stdio.h>
#include <math.h>


double f_x(double x) {

	return (-log10(1 / x) + sin(x));
}



int main(){
	int a, b, c= 0;
	printf("������ ���۰��� �Է��ϼ���:\n");
	scanf_s("%d", &a);
	printf("������ ������ �Է��ϼ���:\n");
	scanf_s("%d", &b);
	printf("������ �ִ� ������ �Է��ϼ���:\n");
	scanf_s("%d", &c);
	double x = a;
	double k = 0;
	for (int i = 0;i <= c;i++) {
		x = a;
		k = 0;
		for (int j = 1;j<=pow(2, i);j++) {
			k += f_x(x) * ((b - a) / pow(2, i));
			x += ((b - a) / pow(2, i));
		}
		printf("���� %d ���� ���: %lf\n", (int)pow(2, i), k);
	}
	
}