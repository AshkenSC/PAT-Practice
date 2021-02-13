/*
0232. Implement Queue using Stacks

使用栈模拟队列操作。也就是说只能使用以下操作：
栈顶添加元素，栈顶访问、取出元素，获取栈大小，查看栈是否为空。

思路：用两个栈a, b模拟队列。

二刷：我之前的写法，写top和pop函数的时候，忘记把辅助栈b里面的元素再放回a，仍然通过了。是测试样例不完备吗？
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
        a.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                int temp = a.top();
                a.pop();
                b.push(temp);
            }
        }
        int popValue = b.top();
        b.pop();

        // 我之前的写法，忘记把b里面的元素再放回a，仍然通过了。
        // 是测试样例不完备吗？
        while (!b.empty()) {
            int temp = b.top();
            b.pop();
            a.push(temp);
        }

        return popValue;
    }
    
    /** Get the front element. */
    int peek() {
        if (b.empty()) {
            while (!a.empty()) {
                int temp = a.top();
                a.pop();
                b.push(temp);
            }
        }
        int topValue = b.top();

        while (!b.empty()) {
            int temp = b.top();
            b.pop();
            a.push(temp);
        }

        return topValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
};