#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct qnode {
	char data;
	struct qnode * next;
} QueueNode;

typedef struct {
	QueueNode *front;
	QueueNode *rear;
} LinkedQueue;

void initLinkedQueue(LinkedQueue *queue) {
	queue->front = malloc(sizeof(QueueNode));
	queue->rear = queue->front;
	queue->rear->next = NULL;
}

int linkedQueueEmpty(LinkedQueue *queue) {
	return queue->front == queue->rear;
}

void linkedEnqueue(LinkedQueue *queue, char x) {
	queue->rear->next = malloc(sizeof(QueueNode));
	queue->rear->next->data = x;
	queue->rear->next->next = NULL;
	queue->rear = queue->rear->next;
}

char linkedQueuePeek(LinkedQueue *queue) {
	if (linkedQueueEmpty(queue)) {
		printf("queue is empty");
		exit(0);
	}
	return queue->front->next->data;
}

char linkedDequeue1(LinkedQueue *queue) {
	if (linkedQueueEmpty(queue)) {
		printf("queue is empty");
		exit(0);
	}
	QueueNode *p;
	char value;
	if (!queue->front->next->next) {
		p = queue->front->next;
		value = p->data;
		queue->rear = queue->front;
		queue->front->next = NULL;
		free(p);
	} else {
		p = queue->front->next;
		value = p->data;
		queue->front->next = p->next;
		free(p);
	}
	return value;
}

char linkedDequeue2(LinkedQueue *queue) {
	if (linkedQueueEmpty(queue)) {
		printf("queue is empty");
		exit(0);
	}
	QueueNode *p = queue->front;
	queue->front = queue->front->next;
	free(p);
	return queue->front->data;
}
