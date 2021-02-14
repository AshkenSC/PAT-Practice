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
        // dp[i][j] 从i开头到j结尾的字符串是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        string res;
        // l -- 被查字符串头尾之间的距离差
        // i -- 字符串起始位置
        // j -- 字符串终结位置
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                // 如果头尾之间距离差为0（总长度为1），则一定是回文串
                if (l == 0) {
                    dp[i][j] = 1;
                }
                // 如果头尾之间距离差为1（总长度为2），只要头尾相同则是回文串
                else if (l == 1) {
                    dp[i][j] = (dp[i] == dp[j]);
                }
                // 否则，[i,j]是否为回文串取决于：
                // 1）头尾是否相等
                // 2）[i+1, j-1]是否为回文串
                else {
                    dp[i][j] = (dp[i] == dp[j] && dp[i + 1][j - 1]);
                }

                // 如果[i,j]为回文串，且比现有最长回文串更长，则更新记录
                if (l + 1 > res.size() && dp[i] == dp[j]) {
                    res = s.substr(i, l + 1);
                }
            }
        }

        return res;
    }
};

