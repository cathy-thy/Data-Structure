/**************************************************************************************************
Description |   MinStack
            |   Time complexity for min, push pop are O(1)
------------+----------------------------------
Details     |   Maintain 2 stacks 
            |   Sorted stack and Data Stack
------------+----------------------------------
Language    |   C++
------------+----------------------------------
Leetcode    |   https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
------------+----------------------------------
Compile     |   g++ -o min-stack min-stack.cpp
            |   ./min-stack
**************************************************************************************************/
#include <cassert>
#include <cstdio>
#include <stack>  

using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> DataStack,SortedStack;
    MinStack() {
        while (!DataStack.empty()) {
            DataStack.pop();
        }
        while (!SortedStack.empty()) {
            SortedStack.pop();
        }
    }
    
    void push(int x) {
        DataStack.push(x);
        if (!SortedStack.empty()){
            if(x<=SortedStack.top()){
                SortedStack.push(x);
            }  
        } else {
            SortedStack.push(x);
        }
    }
    
    void pop() {
        if(DataStack.top() == SortedStack.top()){
            SortedStack.pop();
        }
        DataStack.pop();
        return;
    }
    
    int top() {
        int ele = DataStack.top();
        return ele;
    }
    
    int min() {
        if(DataStack.top() <= SortedStack.top()){
            return DataStack.top();
        } 
        else{
            return SortedStack.top();
        }
    }
};

int main(){
    MinStack stack;
    //obj.SQueue();
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    
    int ele;
    printf("Got %d, expected -3\n", ele = stack.min());
    assert(ele == -3);
    stack.pop();
    printf("Got %d, expected -2\n", ele = stack.min());
    assert(ele == -2);
    printf("Got %d, expected 0\n", ele = stack.top());
    assert(ele == 0);
    stack.pop();
    printf("Got %d, expected -2\n", ele = stack.top());
    assert(ele == -2);    
    printf("Test Completed!\n");
    return 0;
}
