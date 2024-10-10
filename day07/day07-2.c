#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

	double x = 0;
	double y = 0;
	double pi;
	int percent;

	int count = 0, circle = 0;

	srand(time(NULL));

	while (count < 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		count++;

		if (sqrt(pow(x, 2) + pow(y, 2)) <= 1) {
			circle++;
		}

		if (count % 10000000 == 0) {

			pi = 4 * circle / (double)count;

			percent = ((double)count / 1000000000.0) * 100;

			printf("%d%%진행.. 원주율:%lf ", percent, pi);
			for (int i = 0;i < 20;i++) {
				if ((percent / 5) > i) {

					printf("■");
				}
				else printf("□");
			}
			printf("\n");
		}
		
	}
	
	printf("원주율:%lf", pi);


	return 0;
}