#include <stdio.h>
#include <stdlib.h>

struct Node;

struct Node {
	int value;
	int nextNodeSet;
	struct Node* nextNode;
};

struct LinkedList {
	struct Node* head;
};

void linkedListAddEnd(struct LinkedList* l, int val) {
	struct Node* current = l->head;
	while (current->nextNodeSet != 0) {
		current = current->nextNode;
	}
	current->nextNode = (struct Node*)malloc(sizeof(struct Node));
	(current->nextNode)->value = val;
	(current->nextNode)->nextNodeSet = 0;
	current->nextNodeSet = 1;
}

void printLinkedList(struct LinkedList* l) {
	struct Node* current = l->head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->nextNode;
	}
	printf("\n");
}

int main(int argc, char *argv) {
	struct Node h = {53, 0};
	struct LinkedList list = {&h};
	linkedListAddEnd(&list, 61);
	linkedListAddEnd(&list, 84);
	linkedListAddEnd(&list, 27);
	linkedListAddEnd(&list, 97);
	printLinkedList(&list);
}
