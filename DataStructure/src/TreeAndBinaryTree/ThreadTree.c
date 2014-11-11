#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	int ltag, rtag;
	struct node *lChild, *rChild;
} BiThrNode;
typedef BiThrNode * BiThrTree;

// 为给定的二叉树添加线索
void inorderBuild(BiThrTree bt) {
	static BiThrTree * pre;
	if (bt != NULL) {
		inorder(bt->lChild);
		if (!bt->lChild)
			bt->ltag = 1;
		else
			bt->ltag = 0;
		if (!bt->rChild)
			bt->rtag = 1;
		else
			bt->ltag = 0;
		if (pre) {
			if (bt->ltag == 1) {
				bt->lChild = pre;
			}
			if (pre->rtag == 1) {
				pre->rChild = bt;
			}
		}
		inorder(bt->rChild);
	}
}

// 找到后驱结点
BiThrTree * inorderNext(BiThrNode *p) {
	if (p->rtag) {
		return p->rChild;
	}
	p = p->rChild;
	while (p->ltag == 0) {
		p = p->lChild;
	}
	return p;
}

void inorderTravese(BiThrTree bt) {
	BiThrNode *p;
	if (bt) {
		p = bt;
		while (!p->lChild) {
			p = p->lChild;
		}
		do {
			printf("%d", p->data);
			p = inorderNext(p);
		} while (p);
	}
}
