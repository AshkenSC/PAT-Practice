/*
剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：
0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

思路：动态规划经典题。
如果当前位和前一位能够凑成一个两位数（注意是10到25！！）
则dp[i] = dp[i - 1] + dp[i - 2]
否则dp[i] = dp[i - 1]

注意为何dp[0] = 1。因为当10 <= num <= 25时候，dp[2] = 2，因此显然dp[0] = 1
*/

class Solution {
private:
    int getNum(char a, char b) {
        int numA = a - '0';
        int numB = b - '0';
        return numA * 10 + numB;
    }

public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n + 1);
        // 注意为何dp[0] = 1。因为当10 <= num <= 25时候，dp[2] = 2，因此显然dp[0] = 1
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int preTwoDigitsNum = getNum(s[i - 2], s[i - 1]);
            // 如果当前位和前一位能够凑成一个两位数（注意是10到25！！）
            // 则dp[i] = dp[i - 1] + dp[i - 2]
            // 否则dp[i] = dp[i - 1]
            if (preTwoDigitsNum >= 10 && preTwoDigitsNum <= 25) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
};
