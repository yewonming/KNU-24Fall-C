#include <stdio.h>
#include <math.h>


double f_x(double x) {

	return (-log10(1 / x) + sin(x));
}



int main(){
	int a, b, c= 0;
	printf("적분할 시작값을 입력하세요:\n");
	scanf_s("%d", &a);
	printf("적분할 끝값을 입력하세요:\n");
	scanf_s("%d", &b);
	printf("시행할 최대 구간을 입력하세요:\n");
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
		printf("구간 %d 적분 결과: %lf\n", (int)pow(2, i), k);
	}
	
}