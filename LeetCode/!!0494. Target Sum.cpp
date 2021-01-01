/*
0494. Target Sum

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

思路：动态规划。
dp[ i ][ j ] = dp[ i - 1 ][ j - nums[ i ] ] + dp[ i - 1 ][ j + nums[ i ] ]
可以理解为nums[i]这个元素我可以执行加，还可以执行减，那么我dp[i][j]的结果值就是加/减之后对应位置的和。

参考：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-si-kao-quan-guo-cheng-by-keepal/

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (abs(sum) < abs(S)) {
            return 0;
        }

        int len = nums.size();
        int range = sum * 2 + 1;
        vector<vector<int>> dp(len, vector<int>(range));
        if (nums[0] == 0) {
            dp[0][sum] = 2;
        }
        else {
            dp[0][sum + nums[0]] = 1;
            dp[0][sum - nums[0]] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < range; j++) {
                // 边界
                int l = (j - nums[i]) > 0 ? (j - nums[i]) : 0;
                int r = (j + nums[i]) < range ? (j + nums[i]) : 0;
                dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
            }
        }

        return dp[len - 1][sum + S];
    }
};
