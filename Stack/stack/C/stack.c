#include "stack.h"

#include <stdlib.h>

struct stackCDT {
  stackElementT* ele;
  int size;
  int top;
};

stackADT EmptyStack() {
  stackADT stack;
  stack = (stackADT)malloc(sizeof(struct stackCDT));
  stack->ele = (stackElementT*)malloc(10 * sizeof(stackElementT));
  stack->top = -1;
  stack->size = 10;
  return stack;
}

void Push(stackADT stack, stackElementT element) {
  if (stack->top + 1 == stack->size) {  // if the stack is full
    // resize
    stack->ele = (stackElementT*)realloc(stack->ele, stack->size * 2);
    stack->size *= 2;
  }
  stack->top += 1;
  stack->ele[stack->top] = element;
}

stackElementT Pop(stackADT stack) {
  if (stack->top == -1) {
    return '\0';
  }
  stack->top -= 1;
  return stack->ele[stack->top + 1];
}

int StackSize(stackADT stack) { return stack->top + 1; }

int StackIsEmpty(stackADT stack) { return stack->top == -1 ? 1 : 0; }

void Free(stackADT stack) {
  free(stack->ele);
  free(stack);
}
