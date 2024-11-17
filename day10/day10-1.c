#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
	char name[20];
	int score;
	struct Student* next;
};

struct Student* head = NULL;


struct Student* create_std(char name[20], int score) {
	struct Student* new_std = (struct Student*)malloc(sizeof(struct Student));
	strcpy_s(new_std->name, sizeof(name), name);
	new_std->score = score;
	new_std->next = NULL;

	return new_std;
}

int insert_std(struct Student* new_std) {
	struct Student* prev;
	struct Student* cur;

	prev = head;
	cur = head->next;

	while (cur != NULL) {

		if (new_std->score > cur->score) {
			prev->next = new_std;
			new_std->next = cur;
			return 1;
		}

		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL) {
		prev->next = new_std;
		return 2;
	}

	return 0;

}


void print_std() {
	struct Student* cur = head->next;

	printf("�̸�\t\t����\n");
	while (cur != NULL) {
		printf("%s\t:\t%d\n", cur->name, cur->score);

		cur = cur->next;
	}
}


int delete_std(char name[20]) {
	struct Student* prev = head;
	struct Student* cur = NULL;

	cur = head->next;

	while (cur != NULL) {
		if (strcmp(cur->name, name) == 0) { // ������ cur->name == name���� ���Ͽ��µ� �̴� �� ������ �ּҰ��� ���ϴ� ���̹Ƿ� ��������

			if (cur->next == NULL) {
				prev->next = NULL;
			}
			else {
				prev->next = cur->next;
			}
			free(cur);

			return 1;
		}

		prev = cur;
		cur = cur->next;
	}

	return 0;
}


void free_std(struct Student* std) {
	struct Student* cur = std;
	struct Student* next = cur->next;

	while (next != NULL) {
		free(cur);
		cur = next;
		next = next->next;
	}
}

int main() {
	head = (struct Student*)malloc(sizeof(struct Student));
	head->next = NULL;

	char name[20];
	int score;
	int input;


	while (1) {
		printf("1. �л��� ������ �Է�\n");
		printf("2. �л��� ���� ����\n");
		printf("3. ���α׷� ����\n");

		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);
			printf("%s�� ���� : ", name);
			scanf_s("%d", &score);

			insert_std(create_std(name, score));
			break;

		case 2:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);

			delete_std(name);
			break;

		case 3:
			free_std(head);
			return;

		default:

			break;
		}

		printf("---------------------------------------\n");
		print_std();
		printf("---------------------------------------\n");
	}


	return 0;
}