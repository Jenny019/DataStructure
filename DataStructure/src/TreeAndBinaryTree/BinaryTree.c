#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node {
	int data;
	struct node *lChild, *rChild;
} BinNode;

typedef BinNode *BinTree;

// 从广义表建立二叉树
BinNode * createTree(char *str) {
	BinNode *stack[100];
	BinNode *p, *b;
	int top = -1, k, j = 0;
	char ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':
			top++;
			stack[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = malloc(sizeof(BinNode));
			p->data = ch;
			p->lChild = NULL;
			p->rChild = NULL;
			if (b == NULL) {
				b = p;
			} else {
				switch (k) {
				case 1:
					stack[top]->lChild = p;
					break;
				case 2:
					stack[top]->rChild = p;
					break;
				}
			}
		}
	}
	return b;
}

void inorder(BinTree bt) {
	BinNode * stack[100];
	int top = -1;
	stack[++top] = bt;
	while (top != -1) {
		while (stack[top] != NULL) {
			stack[++top] = stack[top - 1]->lChild;
		}
		top--;
		if (top >= 0) {
			printf("%d", stack[top]);
			stack[top] = stack[top]->rChild;
		}
	}
}

int btDepth(BinTree bt) {
	if (bt == NULL) {
		return 0;
	}
	int depL = btDepth(bt->lChild), depR = btDepth(bt->rChild);
	return (depL > depR) ? depL + 1 : depR + 1;
}

int level(BinTree bt, int x, int level) {
	if (bt == NULL) {
		return 0;
	}
	if (x == bt->data) {
		return level;
	}
	int depth = level(bt->lChild, x, level + 1);
	if (depth != 0) {
		return depth;
	}
	return level(bt->rChild, x, level + 1);
}
