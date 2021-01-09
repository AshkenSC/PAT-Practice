'''
0232. Implement Queue using Stacks

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）。

'''

class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stk = []
        self.temp = []
        self.current_queue = 0


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        
        1) 压入stk
        """
        self.stk.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
       
        1）stk所有元素压入temp
        2）出栈一次
        3）temp中剩余元素压回stk，temp清空
        """
        while len(self.stk) > 0:
            self.temp.append(self.stk.pop())
        top = self.temp.pop()
        while len(self.temp) > 0:
            cur = self.temp.pop()
            self.stk.append(cur)
        return top
        
       
    def peek(self) -> int:
        """
        Get the front element.
        
        1）stk所有元素压入temp
        2）top一次
        3）temp元素放回stk
        4）temp清空
        """
        while len(self.stk) > 0:
            self.temp.append(self.stk.pop())
        top = self.temp[-1]
        while len(self.temp) > 0:
            self.stk.append(self.temp.pop())
        return top
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        
        1）检查len(stk)
        """
        return len(self.stk) < 1
   