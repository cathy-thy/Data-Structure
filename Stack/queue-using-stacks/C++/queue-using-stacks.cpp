/**********************************************
Description |   Using two stacks to perform
            |   1. Add tail
            |   2. Delete head
------------+----------------------------------
Details     |   input into stack 1 
            |   
------------+----------------------------------
Language    |   C++
**********************************************/
#include <cassert>
#include <cstdio>
#include <stack>  

using namespace std;
class SQueue {
    stack<int> stack1,stack2;
    public:
        SQueue() {
            while (!stack1.empty()) {
                stack1.pop();
            }
            while (!stack2.empty()) {
                stack2.pop();
            }
        }
        
        void Enqueue(int value) {
            stack1.push(value);
        }
        
        int Dequeue() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            } 
            if (stack2.empty()) {
                return -1;
            } else {
                int deleteItem = stack2.top();
                stack2.pop();
                return deleteItem;
            }
        }
};

int main(){
    SQueue queue;
    //obj.SQueue();
    queue.Enqueue(1);
    queue.Enqueue(3);
    queue.Enqueue(2);
    queue.Enqueue(4);
    
    int ele;
    printf("Got %d, expected 1\n", ele = queue.Dequeue());
    assert(ele == 1);
    printf("Got %d, expected 3\n", ele = queue.Dequeue());
    assert(ele == 3);
    queue.Enqueue(5);
    printf("Got %d, expected 2\n", ele = queue.Dequeue());
    assert(ele == 2);
    //queue.Enqueue(6);
    // assert(!QueueIsEmpty(queue));
    // printf("Got queue length of %d, expected 3\n", QueueLength(queue));
    // assert(QueueLength(queue) == 3);
    printf("Test Completed!\n");
}


