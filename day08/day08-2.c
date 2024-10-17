#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE]){
	printf("�迭 ���:\n");
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}

}
void movePointer(void* array) {

	int x = 0, y = 0;
	int z = *((int*)array + 10 * x + y);
	int count = 0;

	while (1) {
		printf("������ġ:(%d, %d)", x, y);
		printf("�迭�� ��:%d\n", z);	
		count += z;
		if (count > SIZE * SIZE) {

			printf("���̻� �̵��� �� �����ϴ�.\n");
			printf("������ġ:(%d, %d), �迭�� ��:%d", x, y, z);

			break;
		}
		x = count / 10;
		y = count % 10;
		
		
		z = *((int*)array + 10 * x + y);

		
	}
}

int main() {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}