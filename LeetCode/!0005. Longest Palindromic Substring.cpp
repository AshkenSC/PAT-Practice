/*
0005. Longest Palindromic Substring

给你一个字符串 s，找到 s 中最长的回文子串。

思路：动态规划，参考官方题解。其他题解讲的太繁琐了。

参考：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string res;
        // l -- 检查的字符串长度
        // i -- 字符串起始位置
        // j -- 字符串终结位置
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (dp[i] == dp[j]);
                }
                else {
                    dp[i][j] = (dp[i] == dp[j] && dp[i + 1][j - 1]);
                }

                if (l + 1 > res.size() && dp[i] == dp[j]) {
                    res = s.substr(i, l + 1);
                }
            }
        }

        return res;
    }
};

