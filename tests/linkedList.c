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

void linkedListAddBetween(struct LinkedList* l, int val, int idx) {
	struct Node* current = l->head;
	int cnt = 0;
	while (cnt < idx-1) {
		current = current->nextNode;
		cnt++;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->nextNodeSet = 0;
	newNode->nextNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->nextNode = current->nextNode;
	current->nextNode = newNode;
	(current->nextNode)->nextNodeSet = 1;
}

void linkedListDelete(struct LinkedList* l, int idx) {
	struct Node* current = l->head;
	int cnt = 0;
	while (cnt < idx-1) {
		current = current->nextNode;
		cnt++;
	}
	struct Node* newNextNode = (current->nextNode)->nextNode;
	current->nextNode = (struct Node*)malloc(sizeof(struct Node));
	current->nextNode = newNextNode;
}

void linkedListAddStart(struct LinkedList* l, int val) {
	struct Node* prevHead = (struct Node*)malloc(sizeof(struct Node));
	prevHead->value = (l->head)->value;
	prevHead->nextNode = (struct Node*)malloc(sizeof(struct Node));
	prevHead->nextNode = (l->head)->nextNode;
	prevHead->nextNodeSet = 1;
	l->head = (struct Node*)malloc(sizeof(struct Node));
	(l->head)->value = val;
	(l->head)->nextNode = (struct Node*)malloc(sizeof(struct Node));
	(l->head)->nextNode = prevHead;
	(l->head)->nextNodeSet = 1;
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
	linkedListAddBetween(&list, 78, 3);
	linkedListAddBetween(&list, 35, 3);
	printLinkedList(&list);
	linkedListAddStart(&list, 96);
	linkedListAddStart(&list, 26);
	printLinkedList(&list);
	linkedListDelete(&list, 2);
	printLinkedList(&list);
}
