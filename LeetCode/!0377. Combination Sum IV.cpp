/*
0377. Combination Sum IV

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
请注意，顺序不同的序列被视作不同的组合。

思路：动态规划。（这题说是组合，其实按题意是排列）
dp[i]:表示给定正整数i，有多少组合个数。
因为i可以由nums中的某一个数nums[j]，加上i - nums[j]得到，
因此可以组成i - nums[j]的所有排列，再加上一个nums[j]，就都是i的排列了。
对所有小于i的数num[j]，都可这样拆分，因此有：
dp[i] = dp[i - nums[0]] + dp[i - nums[1]] + ...

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