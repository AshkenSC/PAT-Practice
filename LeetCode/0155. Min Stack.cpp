/*
0155. Min Stack

实现一个最小栈，要在常数时间内获取最小值。

主要点在于，栈每次弹出时，如何更新最小值。
注意：在每次更新最小值时，在更新函数的开头，原来错误地将minVal设为stackList[0]，但如果遇到栈pop空的情况，minVal就会遗留为stackList[0]。

*/

class MinStack {
public:
    /** initialize your data structure here. */
    int minVal;
    int stackList[10000];
    int headPos;

    MinStack() {
        minVal = 2147483647;
        headPos = 0;
    }

    void push(int x) {
        stackList[headPos++] = x;
        if (x < minVal)
            minVal = x;
    }

    void pop() {
        headPos = headPos - 1;
        updateMin();
    }

    int top() {
        return stackList[headPos - 1];
    }

    int getMin() {
        return minVal;
    }

    void updateMin() {
        // 这里原来错误地将minVal设为stackList[0]，但如果遇到栈pop空的情况，minVal就会遗留为stackList[0]。
        minVal = -2147483647;
        for (int i = 0; i < headPos; i++) {
            if (stackList[i] <= minVal) {
                minVal = stackList[i];
            }
        }
    }
};