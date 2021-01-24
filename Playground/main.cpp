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
    int lengthOfLongestSubstring(string s) {
       if (s.size() == 0) {
           return 0;
       }

       int start = 0, end = 0;
       int maxLen = 0;
       unordered_set<char> appeared;

       while (end < s.size()) {
           // 当窗口内没有重复字母时，调整右边界
            if (appeared.count(s[end]) == 0) {
               appeared.emplace(s[end++]);
            }
            // 当窗口内出现重复字母时，调整左边界
            // 因为重复的不一定就是s[start]，左边界向右移动一直移动到和end所指的位置元素重复的位置
            // 移动过程中的元素也都要从appeared里删除。
            else {
                maxLen = max(maxLen, end - start);
                while (appeared.count(s[end]) != 0) {
                    appeared.erase(s[start++]);
                }
            }
       }

       maxLen = max(maxLen, end - start);
       return maxLen;
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