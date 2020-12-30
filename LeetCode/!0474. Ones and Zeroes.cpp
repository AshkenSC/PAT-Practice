/*
0474. Ones and Zeroes

给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

思路：动态规划。
参考https://leetcode-cn.com/problems/ones-and-zeroes/solution/dong-tai-gui-hua-0-1bei-bao-wen-ti-labuladongdong-/

*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= strs.size(); i++) {
            // 统计当前字符串中0，1个数
            vector<int> cnt(2);
            for (char c : strs[i - 1]) {
                if (c == '0') {
                    ++cnt[0];
                }
                else {
                    ++cnt[1];
                }
            }

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    // 如果当前物品不能装进背包，继承上一轮的结果
                    if (cnt[0] > j || cnt[1] > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    // 如果当前物品能装进背包，对比：
                    // 1）装进包，则数量为：减去当前物品重量的那一轮dp里的物品数量 + 1
                    // 2）能装而不装，继承上一轮结果的物品数量
                    // 比较二者大小
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                    }

                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

