typedef struct dnode {
	int data;
	struct dnode *prev, *next;
} DListNode;

typedef DListNode * DLinkedList;

// insert a new node before given node
void DLInsert(DListNode *p, int x) {
	DListNode *newNode = malloc(sizeof(DListNode));
	newNode->data = x;
	newNode->next = p;
	newNode->prev = p->prev;
	p->prev->next = newNode;
	p->prev = newNode;
}

// transform a circular single linked list to a circular double linked list
void transform(DLinkedList head) {
	DListNode * p = head;
	while (p->next != head){
		p->next->prev = p;
		p = p->next;
	}
	head->prev = p;
}
