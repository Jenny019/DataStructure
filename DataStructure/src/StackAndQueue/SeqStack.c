#define StackSize 100
typedef struct {
	int top;
	int data[StackSize];
} SeqStack;


void init(SeqStack * stack) {
	stack->top = -1;
}

int isEmpty(SeqStack * stack) {
	return stack->top == -1;
}

int isFull(SeqStack * stack) {
	return stack->top == StackSize - 1;
}

void push(SeqStack *stack, int x) {
	if (isFull(stack)) {
		printf("stack is full");
	} else {
		stack->data[++stack->top] = x;
	}
}

int pop(SeqStack *stack) {
	if (isEmpty(stack)) {
		printf("stack is empty");
		exit(0);
	} else {
		return stack->data[stack->top--];
	}
}

int peek(SeqStack *stack) {
	if (isEmpty(stack)) {
		printf("stack is empty");
		exit(0);
	} else {
		return stack->data[stack->top];
	}
}
