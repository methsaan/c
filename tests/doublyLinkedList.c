#include <stdio.h>
#include <stdlib.h>

struct Node;

// Element in a linked list
struct Node {
	int value; // Value of node
	int nextNodeSet; // 1 = nextNode is initialized, 0 = nextNode is not initialized
	int prevNodeSet; // 1 = nextNode is initialized, 0 = nextNode is not initialized
	struct Node* nextNode; // Address of next node
	struct Node* prevNode; // Address of next node
};

// Set of nodes connected by addresses
struct LinkedList {
	struct Node* head;
};

// Add a node at the tail of the linked list
void linkedListAddEnd(struct LinkedList* l, int val) {
	// Store address of current tail by looping through
	// the list starting from head
	struct Node* current = l->head;
	while (current->nextNodeSet != 0) {
		current = current->nextNode;
	}
	// Create new tail and point current tail to new tail
	current->nextNode = (struct Node*)malloc(sizeof(struct Node));
	(current->nextNode)->value = val;
	(current->nextNode)->nextNodeSet = 0;
	current->nextNodeSet = 1;
	(current->nextNode)->prevNode = current;
	(current->nextNode)->prevNodeSet = 1;
}

// Add a node between two nodes in a linked list
void linkedListAddBetween(struct LinkedList* l, int val, int idx) {
	struct Node* current = l->head;
	// Set current equal to the node before the new node to be added
	int cnt = 0;
	while (cnt < idx-1) {
		current = current->nextNode;
		cnt++;
	}
	// Create new node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->nextNodeSet = 0;
	// Point new node to the node after current
	(current->nextNode)->prevNode = newNode;
	newNode->nextNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->nextNode = current->nextNode;
	// Point current to the new node
	current->nextNode = newNode;
	(current->nextNode)->nextNodeSet = 1;
	(current->nextNode)->prevNode = current;
	(current->nextNode)->prevNodeSet = 1;
}

// Delete element in linked list
void linkedListDelete(struct LinkedList* l, int idx) {
	struct Node* current = l->head;
	// Set current equal to the node before the node to be deleted
	int cnt = 0;
	while (cnt < idx-1) {
		current = current->nextNode;
		cnt++;
	}
	// Set the next node of current to the node after the node to be deleted
	struct Node* newNextNode = (current->nextNode)->nextNode;
	current->nextNode = (struct Node*)malloc(sizeof(struct Node));
	current->nextNode = newNextNode;
	(current->nextNode)->prevNode = current;
}

// Add element to the start of a linked list
void linkedListAddStart(struct LinkedList* l, int val) {
	// Store current head in a new node and point it to second element
	struct Node* prevHead = (struct Node*)malloc(sizeof(struct Node));
	prevHead->value = (l->head)->value;
	prevHead->nextNode = (struct Node*)malloc(sizeof(struct Node));
	prevHead->nextNode = (l->head)->nextNode;
	prevHead->nextNodeSet = 1;
	(prevHead->nextNode)->prevNode = prevHead;
	(prevHead->nextNode)->prevNodeSet = 1;
	// Set head to the given value and point it to the previous head
	l->head = (struct Node*)malloc(sizeof(struct Node));
	(l->head)->value = val;
	(l->head)->nextNode = (struct Node*)malloc(sizeof(struct Node));
	(l->head)->nextNode = prevHead;
	(l->head)->nextNodeSet = 1;
	((l->head)->nextNode)->prevNode = (struct Node*)malloc(sizeof(struct Node));
	((l->head)->nextNode)->prevNode = l->head;
	((l->head)->nextNode)->prevNodeSet = 1;
}

// Print elements of a linked list
void printLinkedList(struct LinkedList* l) {
	struct Node* current = l->head;
	// Print values of linked list nodes until the current node is NULL
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
	linkedListDelete(&list, 4);
	printLinkedList(&list);
}
