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

class Solution {
public:
    void heapify(vector<int>& a, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int curMax = i;

        if (left < heapSize && a[curMax] < a[left]) {
            curMax = left;
        }
        if (right < heapSize && a[curMax] < a[right]) {
            curMax = right;
        }
        if (curMax != i) {
            swap(a[i], a[curMax]);
            heapify(a, curMax, heapSize);
        }
    }

    void buildHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            heapify(a, i, heapSize);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() <= k) {
            return arr;
        }

        // 前k个逐渐增大堆，直到堆容量为k
        // 然后就只比较堆头和arr[i]，如果堆头更大就交换之
        buildHeap(arr, k);
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < arr[0]) {
                swap(arr[i], arr[0]);
                heapify(arr, 0, k);
            }
        }

        // 输出前k个
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
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
    Solution sol;
    vector<int> nums1{0,0,1,2,4,2,2,3,1,4,8};
    vector<int> nums2{1,2,3,4};
    
    vector<int> res = sol.getLeastNumbers(nums1, 8);
    cout << '1';

    return 0;
}