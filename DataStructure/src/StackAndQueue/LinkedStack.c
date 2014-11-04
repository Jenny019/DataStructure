#include <stdlib.h>
#include <malloc.h>
typedef struct stacknode {
	char data;
	struct stacknode *next;
} StackNode;
typedef StackNode * LinkedStack;

int isEmpty(LinkedStack top) {
	return top == NULL;
}

LinkedStack push(LinkedStack top, char x) {
	StackNode *p = malloc(sizeof(StackNode));
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

int pop(LinkedStack top) {
	if (isEmpty(top)) {
		printf("stack is empty");
		exit(0);
	} else {
		int value = top->data;
		StackNode *p = top;
		top = top->next;
		free(p);
		return value;
	}
}

int peek(LinkedStack top) {
	if (isEmpty(top)) {
		printf("stack is empty");
		exit(0);
	} else {
		return top->data;
	}
}


