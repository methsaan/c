#include <stdio.h>
#include <stdlib.h>

struct Node;

// Element in a linked list
struct Node {
	int value; // Value of node
	int nextNodeSet; // 1 = nextNode is initialized, 0 = nextNode is not initialized
	int prevNodeSet; // 1 = prevNode is initialized, 0 = prevNode is not initialized
	struct Node* nextNode; // Address of next node
	struct Node* prevNode; // Address of prev node
};

// Set of nodes connected by addresses
struct LinkedList {
	struct Node* head;
	int len;
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
	(l->len)++;
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
	(l->len)++;
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
	(l->len)--;
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
	(l->len)++;
}

struct Node* getElement(struct Node* linkedListHead, int idx) {
	struct Node* current = linkedListHead;
	int cnt = 0;
	while (cnt < idx) {
		current = current->nextNode;
		cnt++;
	}
	return current;
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

void mergeLinkedList(struct Node* linkedListHead, int segmentIdx1, int segmentIdx2, int len1, int len2) {
	struct Node* currentLeft = (struct Node*)malloc(sizeof(struct Node));
	struct Node* currentRight = (struct Node*)malloc(sizeof(struct Node));
	currentLeft = getElement(linkedListHead, segmentIdx1);
	currentRight = getElement(linkedListHead, segmentIdx2);
	struct LinkedList tempMerged;
	int currentIdx1 = 0;
	int currentIdx2 = 0;
	if (currentLeft->value < currentRight->value) {
		struct Node h = {currentLeft->value, 0};
		tempMerged.head = &h;
		tempMerged.len = 1;
		currentLeft = currentLeft->nextNode;
		currentIdx1++;
	} else {
		struct Node h = {currentRight->value, 0};
		tempMerged.head = &h;
		tempMerged.len = 1;
		currentRight = currentRight->nextNode;
		currentIdx2++;
	}
	while (currentIdx1 < len1 && currentIdx2 < len2) {
		if (currentLeft->value < currentRight->value) {
			linkedListAddEnd(&tempMerged, currentLeft->value);
			currentLeft = currentLeft->nextNode;
			currentIdx1++;
		} else {
			linkedListAddEnd(&tempMerged, currentRight->value);
			currentRight = currentRight->nextNode;
			currentIdx2++;
		}
	}
	if (currentIdx1 < currentIdx2) {
		for (int x = 0; x < len1-currentIdx1; x++) {
			linkedListAddEnd(&tempMerged, currentLeft->value);
			currentLeft = currentLeft->nextNode;
		}
	} else {
		for (int x = 0; x < len2-currentIdx2; x++) {
			linkedListAddEnd(&tempMerged, currentRight->value);
			currentRight = currentRight->nextNode;
		}
	}
	for (int x = 0; x < len1+len2; x++) {
		struct Node* currentNode = getElement(linkedListHead, segmentIdx1+x);
		currentNode->value = getElement(tempMerged.head, x)->value;
		currentNode = currentNode->nextNode;
	}
}

// Merge sort - sort list
// Split list into two at middle index
// Repeat splitting until all elements are in a single-element list
// Merge single-element list with other single-element list from same parent
// by sorting (loop through two lists sequentially and compare adjacent elements
// since both lists are in order)
// Repeat merge for all lists from same parent until original list is in order
void mergeSort(struct Node* listHead, int start, int end, int cnt) {
	cnt++;
	int mid = (start + end)/2;
	struct Node* leftSideHead = getElement(listHead, start);
	struct Node* rightSideHead = getElement(listHead, mid);
	if ((mid-start > 1) && (end-mid > 1)) {
		mergeSort(listHead, start, mid, cnt);
		mergeSort(listHead, mid, end, cnt);
		mergeLinkedList(listHead, start, mid, mid-start, end-mid);
	} else if ((mid-start == 1) && (end-mid > 1)) {
		mergeSort(listHead, mid, end, cnt);
		mergeLinkedList(listHead, start, mid, mid-start, end-mid);
	} else if ((mid-start > 1) && (end-mid == 1)) {
		mergeSort(listHead, start, mid, cnt);
		mergeLinkedList(listHead, start, mid, mid-start, end-mid);
	} else {
		mergeLinkedList(listHead, start, mid, mid-start, end-mid);
	}
}

int main(int argc, char *argv) {
	struct Node h = {53, 0};
	struct LinkedList list = {&h, 1};
	linkedListAddEnd(&list, 61);
	linkedListAddEnd(&list, 84);
	linkedListAddStart(&list, 27);
	linkedListAddEnd(&list, 19);
	linkedListAddStart(&list, 85);
	linkedListAddEnd(&list, 25);
	linkedListAddStart(&list, 83);
	linkedListAddEnd(&list, 35);
	linkedListAddBetween(&list, 34, 4);
	printf("Unsorted: ");
	printLinkedList(&list);
	mergeSort(list.head, 0, list.len, 0);
	printf("Sorted: ");
	printLinkedList(&list);
}
