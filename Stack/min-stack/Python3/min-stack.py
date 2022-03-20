'''
Description |   MinStack
            |   Time complexity for min, push pop are O(1)
------------+----------------------------------
Details     |   This python version is different with C++ version.  
            |   This version doesn't require additional space.
            |   It requires you to calculate the different when append element to the stack
------------+----------------------------------
Language    |   Python3
------------+----------------------------------
Leetcode    |   https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
------------+----------------------------------
Compile     |   g++ -o min-stack min-stack.cpp
            |   ./min-stack
'''


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minVal = -1


    def push(self, x: int) -> None:
        if not self.stack:
            self.stack.append(0) #first element is stored as 0
            self.minVal = x
        else:
            diff = x - self.minVal
            self.stack.append(diff)
            self.minVal = self.minVal if diff > 0 else x

    def pop(self) -> None:
        diff = self.stack.pop()
        if diff > 0:
            return diff+self.minVal
        else:
            self.minVal = self.minVal - diff
            return diff + self.minVal
        
    def top(self) -> int:
        diff = self.stack[-1]
        if diff < 0:
            return self.minVal
        return diff + self.minVal

    def min(self) -> int:
        return self.minVal


def main():
    stack = MinStack()
    stack.push(-2)
    stack.push(0)
    stack.push(-3)

    assert(stack.min() == -3)
    stack.pop()
    assert(stack.min() == -2)
    assert(stack.top() == 0)
    stack.pop()
    assert(stack.top() == -2)   
    print("Test Completed!\n");
    return 

if __name__ == "__main__":
    main()

