
#ifndef MINHEAP_H_
#define MINHEAP_H_
#include "MinHeapN.h"

// Structure to represent a min heap
class MinHeap
{
public:
	int size;	 // Number of heap nodes present currently
	int capacity; // Capacity of min heap
	int *pos;
	MinHeapNode *array;
	MinHeap (int capacity);

	void minHeapify(int idx);
	void decreaseKey(int v, int dist);
	bool isInMinHeap(int v);
	bool isEmpty();
	MinHeapNode extractMin();

};
#endif /* MINHEAP_H_ */
