/*
剑指 Offer 10- II. 青蛙跳台阶问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

本题类似Fibonacci数列。仍然要注意求1e9+7的余数。
*/

class Solution {
public:
    int numWays(int n) {
        vector<long long> dp(3, 1);
        dp[1] = 1; dp[2] = 2;

        if (n < 3) {
            return dp[n];
        }
        
        for (int i = 3; i <= n; ++i) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = (dp[0] + dp[1]) % 1000000007;
        }
        return dp[2];
    }
};
