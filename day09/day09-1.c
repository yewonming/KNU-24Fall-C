#include <stdio.h>
struct Vector {
	int x;
	int y;
	int z;
};

hab(struct Vector n1, struct Vector n2){

	int res1 = n1.x + n2.x;
	int res2 = n1.y + n2.y;
	int res3 = n1.z + n2.z;

	printf("������ ���� x=%d, y=%d z=%d", res1, res2, res3);
}

cha(struct Vector n1, struct Vector n2) {
	int res1 = n1.x - n2.x;
	int res2 = n1.y - n2.y;
	int res3 = n1.z - n2.z;

	printf("������ ���� x=%d, y=%d z=%d", res1, res2, res3);
}
inside(struct Vector n1, struct Vector n2) {
	int res1 = (n1.x * n2.x) + (n1.y * n2.y) + (n1.z * n2.z);
	printf("������ ������ %d", res1);
}
outside(struct Vector n1, struct Vector n2) {
	int res1 = (n1.y * n2.z) - (n1.z * n2.y);
	int res2 = (n1.z * n2.x) - (n1.x * n2.z);
	int res3 = (n1.x * n2.y) - (n1.y * n2.x);
	printf("������ ������ %d, %d, %d", res1, res2, res3);
}
int main() {

	struct Vector n1;
	struct Vector n2;
	int num=0;

	printf("ù��° ����(x, y, z):");
	scanf_s("%d, %d, %d", &n1.x, &n1.y, &n1.z);
	
	printf("�ι�° ����(x, y, z):");
	scanf_s("%d, %d, %d", &n2.x, &n2.y, &n2.z);

	printf("�Էµ� ù��° ����:%d, %d, %d\n",n1.x, n1.y, n1.z);
	printf("�Էµ� �ι�° ����:%d, %d, %d\n", n2.x, n2.y, n2.z);

	printf("1.������ ��\n");
	printf("2.������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");

	scanf_s("%d", &num);
	if (num == 1) {
		hab(n1, n2);
	}else if(num == 2) {
		cha(n1, n2);
	}else if (num == 3) {
		outside(n1, n2);
	}else if (num == 4) {
		inside(n1, n2);
	}else {
		return;
	}
	
	return 0;
}