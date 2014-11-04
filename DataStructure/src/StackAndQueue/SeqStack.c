#include <stdio.h>
#include <stdlib.h>
#define StackSize 100
typedef struct {
	int top;
	char data[StackSize];
} SeqStack;

void init(SeqStack * stack) {
	stack->top = -1;
}

int seqIsEmpty(SeqStack * stack) {
	return stack->top == -1;
}

int isFull(SeqStack * stack) {
	return stack->top == StackSize - 1;
}

void seqPush(SeqStack *stack, char x) {
	if (isFull(stack)) {
		printf("stack is full");
	} else {
		stack->data[++stack->top] = x;
	}
}

char seqPop(SeqStack *stack) {
	if (seqIsEmpty(stack)) {
		printf("stack is empty");
		exit(0);
	} else {
		return stack->data[stack->top--];
	}
}

char seqPeek(SeqStack *stack) {
	if (seqIsEmpty(stack)) {
		printf("stack is empty");
		exit(0);
	} else {
		return stack->data[stack->top];
	}
}

int matchParenthesis() {
	SeqStack stack;
	init(&stack);
	char in;
	scanf("%c", &in);
	while (in != '\n') {
		if (in == '(') {
			seqPush(&stack, in);
		} else if (in == ')') {
			if (seqIsEmpty(&stack)) {
				return 0;
			} else {
				seqPop(&stack);
			}
		}
		scanf("%c", &in);
	}
	return seqIsEmpty(&stack);
}

int symmetric(char str[]) {
	int i = 0, j = 0, length = 0;
	SeqStack stack;
	while (str[i] != '\0') {
		length++;
	}
	for (; i < length / 2; i++) {
		seqPush(&stack, str[i]);
	}
	for (j = (length + 1) / 2; j < length; j++) {
		if (seqPop(&stack) != str[j])
			return 0;
	}
	return 1;
}

void conversion(int i, int d) {
	SeqStack stack;
	init(&stack);
	while (i) {
		seqPush(&stack, i % d);
		i /= d;
	}
	while (!SeqIsEmpty(&stack)) {
		printf("%d", seqPop(&stack));
	}
}

