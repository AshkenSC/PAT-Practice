/*
0062. Unique Paths.cpp

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？

思路：
动态规划，dp[i][j]表示第i行j列有多少不同的路径。
由于机器人只能向右或者向下走，所以对于当前格子，机器人只能从上或者左来。
如果i==0，j==0，那么是起点，则dp[i][j] = 0
如果i==0，j！=0，那么机器人不能从上方来，只能从左来，则dp[i][j] = 1;
如果i！=0，j==0，那么机器人不能从左来，只能从上方来，则dp[i][j] = 1;
其他情况，机器人可能从上方或者左边来，则dp[i][j] = dp[i][j-1] + dp[i-1][j]
*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        return dp[m - 1][n - 1];
    }
};