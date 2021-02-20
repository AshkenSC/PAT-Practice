/*
剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

思路1：其中一个栈直接存储，另一个栈用作缓存。
*/

private:
    stack<int> s1;
    stack<int> s2;

public:
    CQueue() {
    }
    
    void appendTail(int value) {
        s1.emplace(value);
    }
    
    int deleteHead() {
       if (s2.empty() == false) {
           int headValue = s2.top();
           s2.pop();
           return headValue;
       }
       else {
           while (s1.empty() == false) {
               s2.emplace(s1.top());
               s1.pop();
           }
           if (s2.empty() == false) {
                int headValue = s2.top();
                s2.pop();
                return headValue;
           }
           else {
                return -1;
           }
       }
    }
};


// 解法1：自己想的，时间复杂度较高。
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.emplace(value);
    }
    
    int deleteHead() {
        if (s1.size() == 0) {
            return -1;
        }

        // 把s1中除队头元素暂存s2
        while (s1.size() > 1) {
            s2.emplace(s1.top());
            s1.pop();
        }
        // 删除队头
        int headValue = s1.top();
        s1.pop();
        // 将s2中元素放回s1
        while (s2.empty() == false) {
            s1.emplace(s2.top());
            s2.pop();
        }
        
        return headValue;
    }
};
