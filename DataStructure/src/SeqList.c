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
void insert(SeqList * list, int i, int x) {
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
int delete(SeqList * list, int i) {
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
void reverse(SeqList * list){
	if (NULL == list) return;
	int i = 0;
	for (; i < list->length/2; i++){
		int temp = list->data[i];
		list->data[i] = list->data[list->length - i - 1];
		list->data[list->length - i - 1] = temp;
	}
}

//int main() {
//	SeqList list;
//	list.data[0] = 0;
//	list.data[1] = 2;
//	list.length = 2;
//	insert(&list, 2, 1);
//	printf("%d %d %d\n", list.data[0], list.data[1], list.data[2]);
//	reverse(&list);
//	printf("%d %d %d\n", list.data[0], list.data[1], list.data[2]);
//	printf("%d", delete(&list, 1));
//	return 1;
//}
