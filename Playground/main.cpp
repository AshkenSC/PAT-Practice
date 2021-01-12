#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

class Solution {
public:
    void maxHeapify(vector<pair<int, int>>& a, int i, int heapSize) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        
        if (left < heapSize && a[left].second > a[largest].second) {
            largest = left;
        }
        if (right < heapSize && a[right].second > a[largest].second) {
            largest = right;
        }
        if (largest != i) {
            swap(a[largest], a[i]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<pair<int, int>>& a, int heapSize) {
        for (int i = heapSize / 2; i > 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 用map统计数字出现的次数
        unordered_map<int, int> occur;
        for (auto num : nums) {
            if (occur.count(num) == 0) {
                occur[num] = 1;
            }
            else {
                ++occur[num];
            }
        }
        // 用vector<pair<int, int>> 存储统计结果，便于排序
        vector<pair<int, int>> occurList;
        for (auto stat : occur) {
            occurList.push_back(pair<int, int>(stat.first, stat.second));
        }

        // 根据occur构建大根堆
        int heapSize = occurList.size();
        buildMaxHeap(occurList, heapSize);

        // 保存结果
        vector<int> res;
        for (int i = occurList.size() - 1; i >= occurList.size() - k; i--) {
            res.push_back(occurList[0].first);
            swap(occurList[0], occurList[i]);
            --heapSize;
            maxHeapify(occurList, 0, heapSize);
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
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> res = sol.topKFrequent(input, 2);
    for (auto num : res) {
        cout << num << " ";
    }

    return 0;
}