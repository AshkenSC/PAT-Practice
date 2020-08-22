/*
0198. House Robber

作为职业小偷，我要去打家劫舍。但是注意如果两家相邻房子在同一夜被打劫了，则会触发警报。
现在给定一个非负整数构成的数列，代表连续的若干房屋中的财产数量。计算一晚上最多能偷多少钱。
例如：nums = [1,2,3,1]，最大值为1 + 3=4；nums = [2,7,9,3,1]，最大值为2 + 9 + 1 = 12.

思路：动态规划。
f(n) 表示a[0]到a[n-1]家最多能偷多少钱。
如果偷a[n-1]家，那么就不能偷a[n-2]家，则此时值为a[n] + f(n-2)
如果不偷a[n-1]家，那么值为f(n-1)
取二者中较大值：
f(n) = max{f(n-1), a[n-1] + f(n-2)}
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        // 还不要忘了考虑数组长度为0的情况！
        if (len == 0)
            return 0;
        // 注意这里数组大小是n+1。因为我们的定义是：f(n) 表示a[0]到a[n-1]家最多能偷多少钱
        vector<int> dp(len + 1, 0);
        // 要初始化f{0), f(1)
        dp[0] = 0; dp[1] = nums[0];
        // 循环也要相应地注意：最后边界应该是<=len
        for (int i = 2; i <= len; i++) {
            if (dp[i - 1] > nums[i - 1] + dp[i - 2])
                dp[i] = dp[i - 1];
            else
                dp[i] = nums[i- 1] + dp[i - 2];
        }
        return dp[len];     // 这里返回值是f(n)
    }
};