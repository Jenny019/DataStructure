#include <stdio.h>
#include <stdlib.h>
#define StackSize 100
#define QueueSize 100

typedef struct {
	int top;
	char data[StackSize];
} SeqStack;

typedef struct {
	char data[QueueSize];
	int front, rear;
} SeqQueue;

void init(SeqStack * stack) {
	stack->top = -1;
}

int seqIsEmpty(SeqStack * stack) {
	return stack->top == -1;
}

int seqIsFull(SeqStack * stack) {
	return stack->top == StackSize - 1;
}

void seqPush(SeqStack *stack, char x) {
	if (seqIsFull(stack)) {
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
	while (!seqIsEmpty(&stack)) {
		printf("%d", seqPop(&stack));
	}
}

int evaluatePost(SeqQueue queue) {
	SeqStack stack;
	init(&stack);
	while (!seqQueueIsEmpty(&queue)) {
		char c = seqDequeue(&queue);
		if (c > '0' && c < '9') {
			seqPush(&stack, c);
		} else {
			int x = seqPop(&stack) - '0', y = seqPop(&stack) - '0';
			switch (c) {
			case '+':
				seqPush(&stack, (char) (x + y + '0'));
				break;
			case '-':
				seqPush(&stack, (char) (x - y + '0'));
				break;
			case '*':
				seqPush(&stack, (char) (x * y + '0'));
				break;
			case '/':
				seqPush(&stack, (char) (x / y + '0'));
				break;
			}
		}
	}
	return seqPeek(&stack) - '0';
}


void insert(SeqStack *stack1, SeqStack *stack2, char x) {
	if (seqIsFull(stack1) ){
		printf("queue is full");
		exit(0);
	}
	seqPush(stack1);
}

char delete(SeqStack *stack1, SeqStack *stack2) {
	char x;
	if (!seqIsEmpty(stack2)){
		x = seqPop(stack2);
	} else {
		if (seqIsEmpty(stack1)) {
			printf("queue is empty");
			exit(0);
		}
		while (!seqIsEmpty(stack1)) {
			seqPush(stack2, seqPop(stack1));
		}
		x = seqPop(stack2);
	}
	return x;
}
