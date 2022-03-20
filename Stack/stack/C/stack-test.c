#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main() {
	stackADT stack;
    stack = EmptyStack();

    for (int i = 0; i < 5; i++){
        Push(stack, i);
    }
    
    int ele;
    printf("Got %d, expected 4\n", ele = Pop(stack));
    assert(ele == 4);
    printf("Got %d, expected 3\n", ele = Pop(stack));
    assert(ele == 3);
    assert(!StackIsEmpty(stack));
    printf("Got queue length of %d, expected 3\n", StackSize(stack));
    assert(StackSize(stack) == 3);
    printf("Test Completed!\n");
	return 0;
}