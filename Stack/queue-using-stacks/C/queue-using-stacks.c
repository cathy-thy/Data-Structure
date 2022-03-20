/**********************************************
Description |   Using two stacks to perform
            |   1. Enqueue (add element to tail)
            |   2. Dequeue (delete element from head)
------------+----------------------------------
Details     |   enqueue into main stack
            |   whenever dequque, move elements to helper stack and then perform pop in helper stack
------------+----------------------------------
Language    |   C
**********************************************/

#include "queue-using-stacks.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../stack/C/stack.h"


struct queueCDT {
  stackADT main, helper;
};

queueADT EmptyQueue() {
  queueADT queue;
  queue = (queueADT)malloc(sizeof(struct queueCDT));
  queue->main = EmptyStack();
  queue->helper = EmptyStack();
  return queue;
}

void Enqueue(queueADT queue, queueElementT element) {
  Push(queue->main, element);
}

queueElementT Dequeue(queueADT queue) {
  if (StackIsEmpty(queue->helper)) {
    if (StackIsEmpty(queue->main)) {
      printf("Calling Dequeue() on empty queue. Exit.");
      exit(0);
    }
    while (!StackIsEmpty(queue->main)) {
      Push(queue->helper, Pop(queue->main));
    }
  }
  return Pop(queue->helper);
}

int QueueLength(queueADT queue) {
  return StackSize(queue->helper) + StackSize(queue->main);
}

int QueueIsEmpty(queueADT queue) {
  return StackIsEmpty(queue->main) && StackIsEmpty(queue->helper);
}