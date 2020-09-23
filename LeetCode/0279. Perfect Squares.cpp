/*
0279. Perfect Squares

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）
使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

思路：动态规划
因为题目是要求输出“最少”的“个数”，一般来说，要求输出一个最值、且问题规模可以不断缩小的题目可以考虑动态规划。
设dp[n]为组成n的完全平方数最小有多少个。
初始状态：dp[0]=0, dp[1]=1
状态转移方程：dp[n]=min{dp[n-k]} + 1 (其中k为小于n的一个完全平方数)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int minDP = dp[i - 1];
            for (int j = 1; j * j <= i; j++) {
                if (dp[i - j * j] < minDP)
                    minDP = dp[i - j * j];
            }
            dp[i] = minDP + 1;
        }
        return dp[n];
    }
};