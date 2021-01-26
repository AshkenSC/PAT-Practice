#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash;
       for (int i = 0; i < nums.size(); ++i) {
           auto it = hash.find(target - nums[i]);
           if (it != hash.end()) {
               return {it->second, i};
           }
           hash[nums[i]] = i;
       }
       return {};
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