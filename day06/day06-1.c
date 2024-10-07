#include <stdio.h>
#include <stdlib.h>


struct NODE {
	int data;
	struct NODE* link;
}

struct NODE* create_node(int data)
	{
		struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
		new_node->data = data;
		new_node->link = NULL;

		return new_node;
	}

struct NODE* last_node()
{
	struct NODE* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void insert_node_last(struct NODE* new_node)
{
	struct NODE* last = last_node();
	last->link = new_node;
}

void print_nodes() {
	struct NODE* cur = head->link;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->link;
	}
}

struct NODE* find_node(int value)
{
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) return cur;

		cur = cur->link;
	}
	return NULL;
}