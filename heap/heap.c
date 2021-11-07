#include "heap.h"
#include <stdlib.h>

heap_t *heap_init(int max_e){
	heap_t *h = (heap_t *)malloc(sizeof(heap_t));
	h->e = (int *)malloc((max_e + 1)* sizeof(int));
	h->size = 0;
	h->capacity = max_e;
	h->e[0] = INT_MIN;  //infinite minimum, very small value
	return h;
}

void freeHeap(Heap* h) {
	free(h->e);
	free(h);
}

void heap_insert(heap_t *h, int x){
	int i;
	//if (heap_is_full(h)){
	if (h->size==h->capacity){
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	for (i = ++h->size; h->e[i / 2] > x; i /= 2)
		h->e[i] = h->e[i / 2];
	h->e[i] = x;
}

int heap_delete_min(heap_t *h){
	int i, child, min_e, last_e;
	//if (heap_is_empty(h)){
	if (h->size==0){
		fprintf(stderr, "The heap is empty.\n");
		exit(1);
	}
	min_e = h->e[1];
	last_e = h->e[h->size--];
	for (i = 1; i * 2 <= h->size; i = child){
		/* Find smaller child */
		child = i * 2;
		if (child != h->size &&
			h->e[child + 1] < h->e[child])
			child++;
		/* trickle the hole down one level */
		if (last_e > h->e[child])
			h->e[i] = h->e[child];
		else	break;
	}
	h->e[i] = last_e;
	return min_e;
}

void heap_print(heap_t *h){
	int i;
	for (i=1; i<=h->size; i++){
		printf("%d ", h->e[i]);
	}
}
