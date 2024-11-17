#include <stdio.h>
#include <String.h>
#include <stdlib.h>

enum rank {
	r1 = 1,
	r2,
	r3,
	r4,
	r5
};

struct Customer
{
	char* customerName;
	enum rank rank;
	int order_amount;
	int point;
	struct Customer* prev, * next;

};


struct Customer* head = NULL;


struct Customer* create_cus(char name[20], enum rank rank, int order_amount, int point) {
	struct Customer* new_cus = (struct Customer*)malloc(sizeof(struct Customer));
	new_cus->customerName = (char*)malloc(sizeof(char) * 20);
	strcpy_s(new_cus->customerName, sizeof(name), name);
	new_cus->rank = rank;
	new_cus->order_amount = order_amount;
	new_cus->point = point;
	new_cus->prev = NULL;
	new_cus->next = NULL;

	return new_cus;
}

int insert_cus(struct Customer* new_cus) {
	struct Customer* prev = head;
	struct Customer* cur;

	cur = head->next;

	while (cur != NULL) {

		if (new_cus->rank == cur->rank) {
			if (new_cus->order_amount == cur->order_amount) {
				if (new_cus->point > cur->point) {
					new_cus->prev = cur->prev;
					new_cus->prev->next = new_cus;
					new_cus->next = cur;
					cur->prev = new_cus;

					return 1;
				}
			}
			else if (new_cus->order_amount > cur->order_amount) {
				new_cus->prev = cur->prev;
				new_cus->prev->next = new_cus;
				new_cus->next = cur;
				cur->prev = new_cus;

				return 2;
			}
		}
		else if (new_cus->rank < cur->rank) {
			new_cus->prev = cur->prev;
			new_cus->prev->next = new_cus;
			new_cus->next = cur;
			cur->prev = new_cus;

			return 3;
		}

		prev = cur;
		cur = cur->next;

	}

	if (cur == NULL) {
		prev->next = new_cus;
		new_cus->prev = prev;

		return 4;
	}

	return 0;

}


void print_cus() {
	struct Customer* cur = head->next;


	printf("\n---------------------------------------\n");
	printf("이름\t\t등급\t주문량\t포인트\n");

	while (cur != NULL) {
		printf("%s\t:\t%d\t%d\t%d\n", cur->customerName, cur->rank, cur->order_amount, cur->point);

		cur = cur->next;
	}

	printf("---------------------------------------\n");
}

struct Customer* find_cus(char name[20]) {
	struct Customer* cur;

	cur = head->next;

	while (cur != NULL) {
		if (strcmp(cur->customerName, name) == 0) { // 기존에 cur->name == name으로 비교하였는데 이는 두 변수의 주소값을 비교하는 것이므로 옳지않음
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}


int delete_cus(char name[20]) {
	struct Customer* cus = find_cus(name);

	if (cus != NULL) {
		if (cus->next == NULL) {
			cus->prev->next = NULL;
		}
		else {
			cus->prev->next = cus->next;
			cus->next->prev = cus->prev;
		}
		free(cus->customerName);
		free(cus);

		return 1;
	}

	return 0;
}


int fix_cus(char name[20]) {
	struct Customer* cus = find_cus(name);

	if (cus != NULL) {
		printf("\n<고객 정보>\n");
		printf("고객 이름 : %s\n", cus->customerName);
		printf("등급 : %d\n", cus->rank);
		printf("전체 주문량 : %d\n", cus->order_amount);
		printf("포인트 : %d\n", cus->point);


		printf("\n<수정>\n");
		printf("고객 이름 : ");
		scanf_s("%s", cus->customerName, 20);

		printf("등급 : ");
		scanf_s("%d", &cus->rank);

		printf("전체 주문량 : ");
		scanf_s("%d", &cus->order_amount);

		printf("포인트 : ");
		scanf_s("%d", &cus->point);

		if (cus->next == NULL) {
			cus->prev->next = NULL;
		}
		else {
			cus->prev->next = cus->next;
			cus->next->prev = cus->prev;
		}

		cus->prev = NULL;
		cus->next = NULL;
		insert_cus(cus);

		return 1;
	}

	return 0;
}


void free_cus(struct Customer* cus) {
	struct Customer* cur = cus;
	struct Customer* next = cur->next;

	while (cur != NULL) {
		if (cur->customerName != NULL) free(cur->customerName);
		free(cur);
		cur = next;
		next = next != NULL ? next->next : NULL;
	}
}



int main() {
	head = (struct Customer*)malloc(sizeof(struct Customer));
	head->customerName = NULL;
	head->order_amount = NULL;
	head->point = NULL;
	head->prev = NULL;
	head->next = NULL;

	char name[20];
	enum rank rank;
	int r;
	int order;
	int point;
	int input;


	while (1) {
		printf("1. 고객 정보 입력\n");
		printf("2. 고객 정보 제거\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 프로그램 종료\n");

		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("\n<고객 정보 입력>\n");
			printf("고객 이름 : ");
			scanf_s("%s", name, 20);

			printf("등급 : ");
			scanf_s("%d", &r);
			switch (r) {
			case 1:
				rank = r1;
				break;
			case 2:
				rank = r2;
				break;
			case 3:
				rank = r3;
				break;
			case 4:
				rank = r4;
				break;
			case 5:
			default:
				rank = r5;
				break;
			}
			printf("전체 주문량 : ");
			scanf_s("%d", &order);

			printf("포인트 : ");
			scanf_s("%d", &point);


			insert_cus(create_cus(name, rank, order, point));
			break;

		case 2:
			printf("고객 이름 : ");
			scanf_s("%s", name, 20);

			delete_cus(name);
			break;

		case 3:
			printf("고객 이름 : ");
			scanf_s("%s", name, 20);

			fix_cus(name);
			break;

		case 4:
			free_cus(head);
			return;

		default:
			break;
		}

		print_cus();
	}
}