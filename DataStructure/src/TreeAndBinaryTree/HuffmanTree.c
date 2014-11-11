#define n 100
#define m 2*n-1
typedef struct {
	float weight;
	int lChild, rChild, parent;
} HuffmanNode;
typedef HuffmanNode HuffmanTree[m + 1];
