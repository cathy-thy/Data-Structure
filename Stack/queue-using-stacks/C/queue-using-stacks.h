#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueCDT *queueADT;
typedef int queueElementT;

queueADT EmptyQueue();
void Enqueue(queueADT queue, queueElementT element);
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);

#endif  // QUEUE_H


