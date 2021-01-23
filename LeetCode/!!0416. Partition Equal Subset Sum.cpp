/*
0416. Partition Equal Subset Sum

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

思路：0-1背包问题经典题。参考官方解答。

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        // 候选数太少
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(),0);
        // 候选数之和是奇数
        if (sum & 1) {
            return false;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        int target = sum / 2;
        // 候选数的最大数超过target
        if (maxNum > target) {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = 1; j <= target; ++j) {
                // 如果当前目标和大于观察目标数
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                }
                // 否则
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][target];
    }
};
