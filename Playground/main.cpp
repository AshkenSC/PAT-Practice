#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change
/*
1，1，1，1


*/

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    Solution sol;
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> input = {{0},{0}};
    int res = sol.uniquePathsWithObstacles(input);
    cout << res;

    return 0;
}