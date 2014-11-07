#define QueueSize 100
typedef struct {
	char data[QueueSize];
	int front, rear;
} SeqQueue;

void initSeqQueue(SeqQueue *queue) {
	queue->front = queue->rear = 0;
}

int seqQueueIsEmpty(SeqQueue *queue) {
	return queue->front == queue->rear;
}

int seqQueueIsFull(SeqQueue *queue) {
	return (queue->rear + 1) % QueueSize == queue->front;
}

void seqEnqueue(SeqQueue *queue, char x) {
	if (seqQueueIsFull(queue)) {
		printf("queue is full");
		return;
	}
	queue->data[queue->rear++] = x;
}

char seqDequeue(SeqQueue *queue) {
	if (seqQueueIsEmpty(queue)) {
		printf("queque is empty");
		exit(0);
	}
	char temp = queue->data[queue->front];
	queue->front = (queue->front + 1) % QueueSize;
	return temp;
}

char seqQueuePeek(SeqQueue *queue) {
	if (seqQueueIsEmpty(queue)) {
		printf("queque is empty");
		exit(0);
	}
	return queue->data[queue->front];
}

//int main(){
//	return 0;
//}
