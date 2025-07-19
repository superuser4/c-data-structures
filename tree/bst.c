#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

//global variables
int numberOfFullNodes = 0; // full nodes have two children
int numberOfPartialNodes = 0; // partial nodes have one child
int numberOfLeaves = 0; // leaf nodes have no children

typedef struct treeNode {
	int dat;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *newNode(void) {
	return (treeNode *)malloc(sizeof(treeNode));
}

treeNode *addTree(treeNode *Tptr, int dat) {
	if (Tptr == NULL) {
		treeNode *new = newNode();
		new->dat = dat;
		new->left = NULL;
		new->right = NULL;
		return new;
	} else {
		if (dat < Tptr->dat) {
			Tptr->left = addTree(Tptr->left, dat);
		} else {
			Tptr->right = addTree(Tptr->right,dat);
		}
	}
	return Tptr;
}
void preOrderCount(treeNode *Tptr) {
	if (Tptr != NULL) {
		if (Tptr->left != NULL && Tptr->right != NULL) {
			numberOfFullNodes++;
		} else if (Tptr->left == NULL && Tptr->right == NULL) {
			numberOfLeaves++;
		} else if (Tptr->left == NULL || Tptr->right == NULL) {
			numberOfPartialNodes++;
		} 
		preOrderCount(Tptr->left);
		preOrderCount(Tptr->right);
	}
}

int main(void) {
	FILE *fptr = fopen("inputList.txt", "r");
	int number = 0;
	treeNode *root = NULL;
	for (int i = 0; i < SIZE ; i++) {
		fscanf(fptr, "%d", &number);
		root = addTree(root, number);
	}
	preOrderCount(root);
	printf("Number of full nodes: %d\n", numberOfFullNodes);
	printf("Number of partial nodes: %d\n", numberOfPartialNodes);
	printf("Number of leaves: %d\n", numberOfLeaves);
}
