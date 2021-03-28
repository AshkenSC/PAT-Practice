/*
1262. Greatest Sum Divisible by Three

给你一个整数数组 nums，请你找出并返回能被3整除的元素最大和。

思路：
动态规划，网易2021春招笔试题。
f[i][j] 表示到i为止余数为0的最大和。

具体状态转移情况参考解答：
https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/xian-xing-dp-by-mt19937-etfv/
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<vector<int>> f(n + 1, vector<int>(3));
        f[0][0] = 0, f[0][1] = -INT_MAX, f[0][2] = -INT_MAX;

        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 3 == 0) {
                f[i][0] = max(f[i - 1][0], f[i - 1][0] + nums[i - 1]);
                f[i][1] = max(f[i - 1][1], f[i - 1][1] + nums[i - 1]);
                f[i][2] = max(f[i - 1][2], f[i - 1][2] + nums[i - 1]);
            }
            else if (nums[i - 1] % 3 == 1) {
                f[i][0] = max(f[i - 1][0], f[i - 1][2] + nums[i - 1]);
                f[i][1] = max(f[i - 1][1], f[i - 1][0] + nums[i - 1]);
                f[i][2] = max(f[i - 1][2], f[i - 1][1] + nums[i - 1]);
            }
            else {
                f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i - 1]);
                f[i][1] = max(f[i - 1][1], f[i - 1][2] + nums[i - 1]);
                f[i][2] = max(f[i - 1][2], f[i - 1][0] + nums[i - 1]);
            }
        }

        return f[n][0];
    }
};
