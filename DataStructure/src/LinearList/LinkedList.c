#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node *next;
} ListNode;

typedef ListNode * LinkedList;

void printLinkedList(LinkedList head) {
	ListNode *p = head;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

// 头插法建表
LinkedList createListHead() {
	LinkedList head = NULL;
	ListNode *p = NULL;
	int data;
	scanf("%d", &data);
	while (data != -1) {
		p = malloc(sizeof(ListNode));
		if (p == NULL) {
			printf("malloc error!");
			return NULL;
		}
		p->data = data;
		p->next = head;
		head = p;
		scanf("%d", &data);
	}
	return head;
}

// 没有尾指针的尾差法
LinkedList createListEnd() {
	LinkedList head = NULL;
	ListNode * p = NULL;
	int data = 0;
	scanf("%d", &data);
	while (data != -1) {
		p = malloc(sizeof(ListNode));
		if (p == NULL) {
			printf("malloc error!");
			return NULL;
		}
		p->data = data;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		} else {
			ListNode *cur = head;
			while (cur != NULL) {
				if (cur->next == NULL) {
					cur->next = p;
					break;
				}
				cur = cur->next;
			}
		}
		scanf("%d", &data);
	}
	return head;
}

// 带尾指针的尾差法
LinkedList createListRear() {
	LinkedList head = NULL, rear = NULL;
	ListNode *p = NULL;
	int data = 0;
	scanf("%d", &data);
	while (data != -1) {
		p = malloc(sizeof(ListNode));
		if (p == NULL) {
			printf("malloc error!");
			return NULL;
		}
		p->data = data;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		} else {
			rear->next = p;
		}
		rear = p;
		scanf("%d", &data);
	}
	return head;
}

LinkedList createListRearWithHeader() {
	LinkedList head = malloc(sizeof(ListNode));
	if (NULL == head) {
		printf("malloc error!");
		return NULL;
	}
	ListNode * p = NULL, *rear = head;
	int data = 0;
	scanf("%d", &data);
	while (data != -1) {
		p = malloc(sizeof(ListNode));
		if (NULL == p) {
			printf("malloc error!");
			return NULL;
		}
		p->data = data;
		p->next = NULL;
		rear->next = p;
		rear = p;
		scanf("%d", &data);
	}
	return head;
}

// find ith element
ListNode * find(LinkedList head, int i) {
	ListNode *p = head;
	while (p) {
		if (i == 1) {
			return p;
		}
		p = p->next;
		i--;
	}
	return NULL;
}

// find node with data equals given value
ListNode * findValue(LinkedList head, int i) {
	ListNode *p = head;
	while (p) {
		if (p->data == i) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// insert x before ith element
void insertLinkedList(LinkedList head, int i, int x) {
	ListNode *p = head->next, *newNode = malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	if (i == 1) {
		newNode->next = p;
		head->next = newNode;
		return;
	}
	while (p) {
		if (i == 2) {
			newNode->next = p->next;
			p->next = newNode;
			return;
		}
		i--;
		p = p->next;
	}
}

// insert x into a sorted linked list with header
void insertSortedList(LinkedList head, int x) {
	ListNode *p = head, *s = malloc(sizeof(ListNode));
	s->data = x;
	s->next = NULL;
	while (p) {
		if ((p->next && p->next->data >= x) || !p->next) {
			break;
		}
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
	return;
}

// delete the ith node
int deleteLinkedList(LinkedList head, int i) {
	ListNode *p = head, *temp = NULL;
	int data = -1, j = 0;
	if (!p) {
		return -1;
	}
	while (p) {
		if (i - j == 1) {
			temp = p->next;
			if (temp != NULL) {
				p->next = p->next->next;
				data = temp->data;
				free(temp);
				return data;
			} else {
				return -1;
			}
		}
		j++;
		p = p->next;
	}
	return -1;
}

// split list a to list a and b, a containing odd nodes, b containing even nodes
void split(LinkedList a, LinkedList b) {
	ListNode *p = a->next, *r = a, *s = b;
	while (p) {
		r->next = p;
		r = p;
		p = p->next;
		if (p) {
			s->next = p;
			s = p;
			p = p->next;
		}
	}
	r->next = NULL;
	s->next = NULL;
}

LinkedList merge(LinkedList a, LinkedList b) {
	LinkedList c = a;
	ListNode *r = a->next, *s = b->next, *p = c;
	while (r && s) {
		if (r->data <= s->data) {
			p->next = r;
			p = r;
			r = r->next;
		} else {
			p->next = s;
			p = s;
			s = s->next;
		}
	}
	p->next = (r) ? r : s;
	free(b);
	return c;
}

// reverse node p with its next node
void reverseCurrentAndNext(LinkedList head, ListNode *p) {
	ListNode *cur = head, *q = NULL;
	if (!p || !head || p == head) {
		return;
	}
	while (cur && cur->next != p) {
		cur = cur->next;
	}
	if (!cur || !cur->next->next) {
		return;
	}
	q = p->next;
	p->next = q->next;
	q->next = p;
	cur->next = q;
}

// compute a sorted linked list of the intersect of two sorted linked list
LinkedList intersect(LinkedList listA, LinkedList listB) {
	LinkedList listC = malloc(sizeof(ListNode));
	if (!listC) {
		printf("malloc failed.");
		return NULL;
	}
	listC->next = NULL;
	ListNode *p = listA, *q = listB, *k = listA, *cur = listC, *temp = NULL;
	for (; q; q = q->next) {
		free(q);
		for (p = k; p; p = p->next) {
			free(temp);
			if (p->data <= q->data) {
				k = p;
			} else {
				continue;
			}
			if (p->data == q->data) {
				cur->next = p;
				cur = p;
			} else {
				temp = p;
			}
		}
		temp = q;
	}
	cur->next = NULL;
	return listC;
}

int main() {
	LinkedList listA = createListRear();
	LinkedList listB = createListRear();
	LinkedList listC = intersect(listA, listB);
	//	insertSortedList(list, 4);
//	insertSortedList(list, 3);
//	insertSortedList(list, 0);
	printLinkedList(listC);
	return 0;
}

