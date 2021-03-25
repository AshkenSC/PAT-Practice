/*
剑指 Offer 59 - II. 队列的最大值

请定义一个队列并实现函数 max_value 得到队列里的最大值，
要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1

思路：
参考官方解答。维护一个非递减的双端队列，用于输出最大值。
*/

class MaxQueue {
    queue<int> q;
    deque<int> d;

public:
    MaxQueue() {

    }
    
    int max_value() {
        if (d.empty()) {
            return -1;
        }
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()) {
            return -1;
        }
        int ans = q.front();
        if (d.front() == ans) {
            d.pop_front();
        }
        q.pop();

        return ans;
    }
};
