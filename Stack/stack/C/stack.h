#ifndef stack_H
#define stack_H

typedef struct stackCDT *stackADT;

typedef char stackElementT;

stackADT EmptyStack();
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackSize(stackADT stack);
int StackIsEmpty(stackADT stack);
void Free(stackADT stack);

#endif

