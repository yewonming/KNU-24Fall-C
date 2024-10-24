#include <stdio.h>
struct Product {
	int ID;
	char name[100];
	int price;
};
void printProduct(struct Product n1) {
	printf("상품ID: % d\n, 상품명: % s\n, 가격:% d\n", n1.ID, n1.name, n1.price);
}

int main() {
	struct Product arr[5];

	int count = 0;

	while(count<5){

		printf("상품 정보를 입력하세요(입력 중단은 id에 0 입력)\n");
		printf("상품 ID:");
		scanf_s("%d", &arr[count].ID);
		if (arr[count].ID == 0) {
			break;
		}
		printf("상품명:");
		scanf_s("%s", arr[count].name, sizeof(arr[count].name));
		printf("가격:");
		scanf_s("%d", &arr[count].price);

		count++;
	}
	for (int i = 0; i < count;i++) {
		printProduct(arr[i]);
	}

	return 0;
}