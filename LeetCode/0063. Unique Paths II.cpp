/*
0063. Unique Paths II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

思路：
本人思路：递推公式基本不变，根据来的方向是否有石头确定是否计算上方/左方的路径数。
但其实是有问题的：如果来的方向本来就有石头，那肯定就没有路径了！
所以其实应该直接判断当前格子本身是否是有石头的。


*/


// 本人错误思路
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] * (1- obstacleGrid[i - 1][j]) + dp[i][j - 1] * (1 - obstacleGrid[i][j - 1]);
            }
        }

        return !obstacleGrid[m - 1][n - 1] && !obstacleGrid[0][0] ? dp[m - 1][n - 1] : 0;
    }
};
*/