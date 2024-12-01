#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE* next;
};

struct NODE* head = NULL;

struct NODE* create_node(int data) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert_node(struct NODE* new_node) {
	struct NODE* cur = head;
	
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = new_node;
}

void print_node(){
	struct NODE* cur = head;

	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
		
	}
}

void free_node() {
	struct NODE* cur = head;
	struct NODE* next = cur->next;

	while (cur->next != NULL) {
		free(cur);
		cur = next;
		next = next->next;

	}
}


int main() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->next = NULL;
	insert_node(create_node(1));
	insert_node(create_node(2));
	insert_node(create_node(3));
	insert_node(create_node(4));
	insert_node(create_node(5));

	print_node();

	return 0;
}