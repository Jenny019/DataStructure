#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node *next;
} ListNode;

typedef ListNode * LinkedList;

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

void printLinkedList(LinkedList head) {
	ListNode *p = head;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int main() {
	LinkedList list = createListRearWithHeader();
	/*printf("%d %d %d", find(list, 1)->data, find(list, 2)->data,
	 find(list, 3)->data);*/
	insertLinkedList(list, 1, 5);
	insertLinkedList(list, 2, 6);
	insertLinkedList(list, 6, 7);
	printLinkedList(list);
	printf("\n");
	deleteLinkedList(list, 1);
	deleteLinkedList(list, 2);
	deleteLinkedList(list, 3);
	printLinkedList(list);
	return 0;
}

