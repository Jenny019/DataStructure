#define ListSize 100

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data[ListSize];
	int length;
} SeqList;

// insert x into list, before position i
// average move: n - i + 1
void insertSeq(SeqList * list, int i, int x) {
	if (i < 1 || i > list->length) {
		printf("index overflow!");
		return;
	}
	int j = list->length;
	for (; j >= i; j--) {
		list->data[j] = list->data[j - 1];
	}
	list->data[i - 1] = x;
	list->length++;
}

// delete the ith element
// average move: n - i
int deleteSeq(SeqList * list, int i) {
	if (i < 1 || i > list->length) {
		printf("index overflow");
		return -1;
	}
	int j = i - 1;
	int temp = list->data[i - 1];
	for (; j < list->length - 1; j++) {
		list->data[j] = list->data[j + 1];
	}
	list->data[list->length - 1] = 0;
	list->length--;
	return temp;
}

// reverse a sequential list
void reverseSeq(SeqList * list) {
	if (NULL == list)
		return;
	int i = 0;
	for (; i < list->length / 2; i++) {
		int temp = list->data[i];
		list->data[i] = list->data[list->length - i - 1];
		list->data[list->length - i - 1] = temp;
	}
}

// compute A - B, with A and B in ascending order
void computeAExcpetB(SeqList *a, SeqList *b) {
	int i = 0, j = 0, k = 0;
	for (; i < b->length; i++) {
		if (a->data[a->length - 1] < b->data[i]) {
			break;
		}
		for (j = k; j < a->length; j++) {
			if (a->data[j] <= b->data[i]) {
				k = j;
			} else {
				continue;
			}
			if (a->data[j] == b->data[i]) {
				deleteSeq(a, j + 1);
			}
		}
	}
}

void printSeqList(SeqList *list) {
	int i = 0;
	for (; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
}

//int main() {
//	SeqList listA, listB;
//	listA.data[0] = 0;
//	listA.data[1] = 1;
//	listA.data[2] = 2;
//	listA.data[3] = 3;
//	listA.data[4] = 4;
//	listA.length = 5;
//
//	listB.data[0] = 0;
//	listB.data[1] = 3;
//	listB.data[2] = 5;
//	listB.length = 3;
//
//	computeAExcpetB(&listA, &listB);
//	printSeqList(&listA);
//	return 1;
//}
