/*
0377. Combination Sum IV

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
请注意，顺序不同的序列被视作不同的组合。

思路：动态规划。
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long> dp(target + 1);

        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};