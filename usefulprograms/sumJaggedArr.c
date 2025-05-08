#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef struct Tree {
	int val;
	int hasVal;
	int numOfSubtrees;
	struct Tree** subtrees;
} Tree;

struct Tree* initTree(int rootVal, int hasRootVal, int rootNumSubtrees) {
	struct Tree* tree = malloc(sizeof(Tree));
	tree->val = rootVal;
	tree->hasVal = hasRootVal;
	tree->numOfSubtrees = rootNumSubtrees;
	if (rootNumSubtrees > 0) {
		tree->subtrees = malloc(rootNumSubtrees * sizeof(Tree *));
	} else {
		tree->subtrees = NULL;
	}
	return tree;
}

void treeAddSubtree(struct Tree* root, int idx, struct Tree* subtree) {
	if (root->subtrees == NULL) {
		return;
	}
	if (idx >= root->numOfSubtrees || idx < 0) {
		return;
	}
	root->subtrees[idx] = subtree;
}

struct Tree* treeGetSubtree(struct Tree* root, int idx) {
	if (root->subtrees == NULL) {
		return NULL;
	}
	if (idx >= root->numOfSubtrees || idx < 0) {
		return NULL;
	}
	return root->subtrees[idx];
}

struct Tree* createJaggedArr(int currentLevel, int idx) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long long seed = (unsigned long long)(tv.tv_sec) * 1000000 + tv.tv_usec;
	srand(seed);
	int randNum;
	struct Tree* jaggedArr = malloc(sizeof(Tree));
	int len, value = 0;
	char arrOrInt[2] = "A";
	if (currentLevel == 1) {
		randNum = rand() % 2;
		if (randNum == 1 || currentLevel == 6) {
			arrOrInt[0] = 'I';
		}
	}
	if (strcmp(arrOrInt, "A") == 0) {
		len = currentLevel < 3 ? rand() % 7 : rand() % (rand() % 2 + 2);
		len += currentLevel < 3 ? rand() % 7 : rand() % (rand() % 2 + 2);
		len /= 2;
	} else {
		value = (rand() % 1000 + rand() % 500) * 3 / 2;
	}
	if (strcmp(arrOrInt, "A") == 0 && len == 0) {
		jaggedArr = initTree(0, 0, len); // val = 0, hasVal = 0, numOfSubtrees = len = 0
		return jaggedArr; // []
	} else if (strcmp(arrOrInt, "I") == 0) {
		jaggedArr = initTree(value, 1, 0); // val = value, hasVal = 1, numOfSubtrees = 0
		return jaggedArr; // value
	} else if (strcmp(arrOrInt, "A") == 0 && len > 0) {
		jaggedArr = initTree(0, 0, len); // val = 0, hasVal = 0, numOfSubtrees = len
		for (int i = 0; i < len; i++) {
			struct Tree* element = malloc(sizeof(Tree));
			char* elementValStr = malloc(sizeof(char));
			randNum = rand() % 2;
			
			if (randNum == 0) {
				int elementVal = rand() % 1000;
				element = initTree(elementVal, 1, 0); // [..., n, ...]
			} else {
				element = createJaggedArr(currentLevel + 1, i);;;;;;;;;;;; // [..., [...], ...]
			}
			treeAddSubtree(jaggedArr, i, element);
		}
		return jaggedArr;
	} else {
		return NULL;
	}
}

void printJaggedArr(struct Tree* jaggedArr, int level) {
	if (jaggedArr == NULL) {
		return;
	}
	if (jaggedArr->hasVal == 1) {
		printf("%d", jaggedArr->val);
	} else {
		printf("{");
		for (int i = 0; i < jaggedArr->numOfSubtrees; i++) {
			printJaggedArr(jaggedArr->subtrees[i], level + 1);
			if (i < jaggedArr->numOfSubtrees - 1) {
				printf(", ");
			}
		}
		printf("}");
	}
}

int sumLeaves(struct Tree* tree) {
	if (tree->subtrees == NULL && tree->hasVal == 0) {
		return 0;
	} else if (tree->hasVal == 1) {
		return tree->val;
	} else {
		int sum = 0;
		for (int i = 0; i < tree->numOfSubtrees; i++) {
			sum += sumLeaves(tree->subtrees[i]);
		}
		return sum;
	}
}

int main(int argc, char* argv[]) {
	for (int x = 0; x < 10; x++) {
		struct Tree* jaggedArr = createJaggedArr(1, 0);
		printJaggedArr(jaggedArr, 1);
                printf(" - Sum: %d\n", sumLeaves(jaggedArr));
		free(jaggedArr->subtrees);
		free(jaggedArr);
	}
}
