/*
0232. Implement Queue using Stacks

使用栈模拟队列操作。也就是说只能使用以下操作：
栈顶添加元素，栈顶访问、取出元素，获取栈大小，查看栈是否为空。

思路：用两个栈a, b模拟队列。
*/

class MyQueue {
public:

    stack<int> a;
    stack<int> b;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                int current = a.top();
                a.pop();
                b.push(current);
            }
        }
        int popValue = b.top();
        b.pop();
        return popValue;
    }

    /** Get the front element. */
    int peek() {
        if (b.empty()) {
            while (!a.empty()) {
                int current = a.top();
                a.pop();
                b.push(current);
            }
        }
        return b.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};