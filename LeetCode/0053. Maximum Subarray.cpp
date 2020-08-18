/*
0053. Maximum Subarray

给定一个整数数组，找到和最大的子数组，并返回这个和。

思路：动态规划
初始状态：a[0] = nums[0]
第 i 个子组合的最大值为：第i-1个子组合的最大值加第 i 个数字，或第i个数字本身
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp;
        dp.resize(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
        }
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i] > maxSum)
                maxSum = dp[i];
        }
        return maxSum;
    }
};