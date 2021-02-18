/*
0070. Climbing Stairs

f(n) 表示爬到第n级台阶，则f(n) = f(n-1) + f(n-2)，（因为只能走一步或者两步）
初始条件：f(0)=1, f(1)=1
由于只关心当前f(n)和前两个f(n-1), f(n-2)，所以可以只用三个变量存储之，而不用dp[n]数组。
*/


// 二刷
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        
        int dpMinus2 = 1, dpMinus1 = 2, dp;
        
        for (int i = 3; i <= n; ++i) {
            dp = dpMinus1 + dpMinus2;
            dpMinus2 = dpMinus1;
            dpMinus1 = dp;
        }

        return dp;
    }
};


// 一刷
class Solution {
public:
    int climbStairs(int n) {
        int current = 1, currentPre = 0, currentPrePre = 0;
        for (int i = 1; i <= n; i++) {
            currentPrePre = currentPre;
            currentPre = current;
            current = currentPre + currentPrePre;
        }
        return current;
    }
};