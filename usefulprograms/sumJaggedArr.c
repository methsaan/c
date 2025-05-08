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

Tree* initTree(int rootVal, int hasRootVal, int rootNumSubtrees) {
	Tree* tree = malloc(sizeof(Tree));
	if (!tree) {
		perror("Malloc");
		return NULL;
	}
	tree->val = rootVal;
	tree->hasVal = hasRootVal;
	tree->numOfSubtrees = rootNumSubtrees;
	if (rootNumSubtrees > 0) {
		tree->subtrees = malloc(rootNumSubtrees * sizeof(Tree));
		if (!tree->subtrees) {
			perror("Malloc");
			free(tree);
			return NULL;
		}
	} else {
		tree->subtrees = NULL;
	}
	return tree;
}

void treeAddSubtree(Tree* root, int idx, Tree* subtree) {
	if (root->subtrees == NULL) {
		return;
	}
	if (idx >= root->numOfSubtrees || idx < 0) {
		return;
	}
	root->subtrees[idx] = subtree;
}

Tree* createTree(int currentLevel) {
	int randNum;
	struct Tree* tree;
	int len, value = 0;
	int isArr = currentLevel > 1 && currentLevel < 6;
	if (currentLevel == 1) {
		isArr = rand() % 2;
	}
	if (isArr) {
		len = currentLevel < 3 ? rand() % 7 : rand() % (rand() % 2 + 2);
		len += currentLevel < 3 ? rand() % 7 : rand() % (rand() % 2 + 2);
		len /= 2;
	} else {
		value = (rand() % 1000 + rand() % 500) * 3 / 2;
	}
	if (isArr && len == 0) {
		tree = initTree(0, 0, len); // val = 0, hasVal = 0, numOfSubtrees = len = 0
		return tree; // {}
	} else if (!isArr) {
		tree = initTree(value, 1, 0); // val = value, hasVal = 1, numOfSubtrees = 0
		return tree; // value
	} else if (isArr && len > 0) {
		tree = initTree(0, 0, len); // val = 0, hasVal = 0, numOfSubtrees = len
		for (int i = 0; i < len; i++) {
			Tree* element;
			randNum = rand() % 2;
			
			if (randNum == 0) {
				int elementVal = rand() % 1000;
				element = initTree(elementVal, 1, 0); // {..., n, ...}
			} else {
				element = createTree(currentLevel + 1); // {..., {...}, ...}
			}
			treeAddSubtree(tree, i, element);
		}
		return tree;
	} else {
		return NULL;
	}
}

void printTree(Tree* tree) {
	if (tree == NULL) {
		return;
	}
	if (tree->hasVal == 1) {
		printf("%d", tree->val);
	} else {
		printf("{");
		for (int i = 0; i < tree->numOfSubtrees; i++) {
			printTree(tree->subtrees[i]);
			if (i < tree->numOfSubtrees - 1) {
				printf(", ");
			}
		}
		printf("}");
	}
}

int sumLeaves(Tree* tree) {
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

void freeTree(struct Tree* tree) {
	if (!tree) {
		return;
	}
	for (int i = 0; i < tree->numOfSubtrees; i++) {
		freeTree(tree->subtrees[i]);
	}
	free(tree->subtrees);
	free(tree);
}

int main(int argc, char* argv[]) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long long seed = (unsigned long long)(tv.tv_sec) * 1000000 + tv.tv_usec;
	srand(seed);
	for (int x = 0; x < 10; x++) {
		Tree* jaggedArr = createTree(1);
		printTree(jaggedArr);
		printf(" - Sum: %d\n", sumLeaves(jaggedArr));
		freeTree(jaggedArr);
	}
}
