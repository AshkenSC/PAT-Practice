/*
0221. Maximal Square

在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

思路：动态规划经典题，
总体思路，参考官方题解。
递推方程的推导证明，参考：https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> dp;
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        }

        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }

                    maxSide = max(dp[i][j], maxSide);
                }
            }
        }

        return maxSide * maxSide;
    }
};
