#include <stdio.h>
struct Product {
	int ID;
	char name[100];
	int price;
};
void printProduct(struct Product n1) {
	printf("��ǰID: % d\n, ��ǰ��: % s\n, ����:% d\n", n1.ID, n1.name, n1.price);
}

int main() {
	struct Product arr[5];

	int count = 0;

	while(count<5){

		printf("��ǰ ������ �Է��ϼ���(�Է� �ߴ��� id�� 0 �Է�)\n");
		printf("��ǰ ID:");
		scanf_s("%d", &arr[count].ID);
		if (arr[count].ID == 0) {
			break;
		}
		printf("��ǰ��:");
		scanf_s("%s", arr[count].name, sizeof(arr[count].name));
		printf("����:");
		scanf_s("%d", &arr[count].price);

		count++;
	}
	for (int i = 0; i < count;i++) {
		printProduct(arr[i]);
	}

	return 0;
}