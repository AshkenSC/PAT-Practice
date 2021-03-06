#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <stack>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

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
        // 首先我们约定：small中元素个数大于等于large中元素个数
        // 因此，如果当前已存数量为偶数，就将num插入small，small经过调整后的队头移入large
        // 如果当前已存数量为奇数，就将num插入large，large经过调整后的队头移入small
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
            median = (double)small.top();
        }
        return median;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    //Solution sol;
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    double a = m.findMedian();
    m.addNum(3);
    double b = m.findMedian();

    cout << '1';

    return 0;
}