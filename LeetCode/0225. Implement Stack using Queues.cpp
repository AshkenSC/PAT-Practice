/*
0225. Implement Stack using Queues

使用队列去模拟栈操作。也就是说只能使用以下操作：
队尾添加元素，队首访问、取出元素，获取队列大小，查看队列是否为空。

在push时，每次插入，都将新元素添加到队尾，然后原队列元素用循环向后移动一位。这样新元素就在队首了。
*/

class MyStack {
public:
    queue<int> qStack;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        // 每次插入，都将新元素添加到队尾，然后原队列元素用循环向后移动一位
        int qSize = qStack.size();
        qStack.push(x);
        while (qSize > 0) {
            int temp = qStack.front();
            qStack.pop();
            qStack.push(temp);
            qSize--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int poppedElement = qStack.front();
        qStack.pop();
        return poppedElement;
    }

    /** Get the top element. */
    int top() {
        return qStack.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qStack.empty();
    }
};