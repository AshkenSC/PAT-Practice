/*
剑指 Offer 30. 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。

思路：构建辅助栈，辅助栈是非递增的。
当新加入元素比辅助栈顶小，才压入辅助栈。
当出栈时，如果出栈元素同时是最小元素（表现为出栈元素==辅助栈顶元素），则辅助栈也出栈。

参考：
https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/solution/mian-shi-ti-30-bao-han-minhan-shu-de-zhan-fu-zhu-z/
*/

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        dataStack.emplace(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.emplace(x);
        }
    }
    
    void pop() {
        int currentTop = dataStack.top();
        dataStack.pop();
        if (minStack.top() == currentTop) {
            minStack.pop();
        }
    }
    
    int top() {
        return dataStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};

