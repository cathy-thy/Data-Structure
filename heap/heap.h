
heap_t *heap_init(int max_e);
void 	 heap_free(heap_t *h);
void 	 heap_insert(heap_t *h, int x);
int 	 heap_delete_min(heap_t *h);
int 	 heap_find_min(heap_t *h);
void 	 heap_print(heap_t *h);
//void 	 heap_make_empty(heap_t *h);
//int 	 heap_is_full(heap_t *h);
//int 	 heap_is_empty(heap_t *h);
