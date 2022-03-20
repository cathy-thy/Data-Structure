#include "queue-using-stacks.h"

#include <assert.h>
#include <stdio.h>

int main() {
  queueADT queue = EmptyQueue();

  assert(QueueIsEmpty(queue));
  Enqueue(queue, 1);
  Enqueue(queue, 3);
  Enqueue(queue, 2);
  Enqueue(queue, 4);
  int ele;
  printf("Got %d, expected 1\n", ele = Dequeue(queue));
  assert(ele == 1);
  printf("Got %d, expected 3\n", ele = Dequeue(queue));
  assert(ele == 3);
  Enqueue(queue, 5);
  printf("Got %d, expected 2\n", ele = Dequeue(queue));
  assert(ele == 2);
  Enqueue(queue, 6);
  assert(!QueueIsEmpty(queue));
  printf("Got queue length of %d, expected 3\n", QueueLength(queue));
  assert(QueueLength(queue) == 3);
  printf("Test Completed!\n");
  return 0;
}
