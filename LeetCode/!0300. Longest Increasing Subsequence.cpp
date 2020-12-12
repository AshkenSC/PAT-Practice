/*
0300. Longest Increasing Subsequence

给定一个无序的整数数组，找到其中最长上升子序列的长度。

思路：

注意一点：最长上升子序列不一定要是*连续*的！
比如题目给出的例子：[10,9,2,5,3,7,101,18]，最长的上升子序列是 [2,3,7,101]，跳过了5.

动态规划经典题。
dp[i]表示以nums[i]结尾的最长上升子序列的长度。
初始化dp数组元素全为1.
状态转移方程为dp[i] = max{1 + dp[j] for j < i if dp[j] < dp[i]}
*/

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        int len = nums.size();
        vector<int> dp(len, 1);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < dp[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};


