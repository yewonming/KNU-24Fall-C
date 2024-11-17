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

	printf("이름\t\t점수\n");
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
		if (strcmp(cur->name, name) == 0) { // 기존에 cur->name == name으로 비교하였는데 이는 두 변수의 주소값을 비교하는 것이므로 옳지않음

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
		printf("1. 학생의 성적을 입력\n");
		printf("2. 학생의 정보 제거\n");
		printf("3. 프로그램 종료\n");

		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("학생의 이름 : ");
			scanf_s("%s", name, 20);
			printf("%s의 성적 : ", name);
			scanf_s("%d", &score);

			insert_std(create_std(name, score));
			break;

		case 2:
			printf("학생의 이름 : ");
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