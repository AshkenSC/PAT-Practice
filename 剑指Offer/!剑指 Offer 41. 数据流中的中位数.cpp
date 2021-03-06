/*
剑指 Offer 41. 数据流中的中位数

设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

思路：设计一个大根堆保存较小的数，一个小根堆保存较大的数。
因为我们只关注中间的一个或者两个数，所以这样设计。

参考：
https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/mian-shi-ti-41-shu-ju-liu-zhong-de-zhong-wei-shu-y/
*/

class MedianFinder {
private:
    // 大根堆存放小数，小根堆存放大数
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int> small;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 如果当前已存数量为偶数，就将num插入small，small经过调整后的队头移入large
        // 如果当前已存数量为奇数，就将num插入large，large经过调整后的队头移入small
        // 此处只是这样约定而已，如果反过来约定也是可以的
        // 但是后面输出中位数时，奇数情形要对应修改为small.top()
        if (large.size() == small.size()) {
            small.emplace(num);
            int smallTop = small.top();
            small.pop();
            large.emplace(smallTop);
        }
        else {
            large.emplace(num);
            int largeTop = large.top();
            large.pop();
            small.emplace(largeTop);
        }
    }
    
    double findMedian() {
        double median;
        if (large.size() == small.size()) {
            median = (large.top() + small.top()) / 2.0;
        }
        else {
            median = (double)large.top();
        }
        return median;
    }
};
