#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int largest = i;
        if (left < heapSize && a[left] > a[largest]) {
            largest = left;
        }
        if (right < heapSize && a[right] > a[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(a[largest], a[i]);
            maxHeapify(a, i, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            maxHeapify(nums, 0, --heapSize);
        }
        return nums[0];
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
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> res = sol.topKFrequent(input, 2);
    for (auto num : res) {
        cout << num << " ";
    }

    return 0;
}