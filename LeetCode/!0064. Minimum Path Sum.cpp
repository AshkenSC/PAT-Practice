/*
0064. Minimum Path Sum

给定m*n个填了非负数的格子，找从左上角到右下角的路径，并且这条路径上的数之和还要最小。
只能向下或者向右移动。

思路：
初步想法：是否可以用动态规划，但是本题走的步数是不确定的，所以f(n)的n就不确定。
然后发现，只能向下或者向右移动，所以一定是计算f(4)。
f(0)=0, f(1)=1
f(n) = f(n-1) + max{向下走，向右走}
但是自己写起来太繁琐了。

参考答案思路：
和个人思路不同的是，递推公式考虑的不是当前格子的下一步是哪个格子，而是考虑从上一个状态走到当前状态，是经过哪个格子。
设当前格子为(i, j)，要注意分为四种情况：
1）当前格子只能从右边来，则dp[i][j] = dp[i][j-1] + grid[i][j]
2）当前格子只能从上方来，则dp[i][j] = dp[i-1][j] + grid[i][j]
3）当前格子是起始位置，则dp[i][j] = grid[i][j]
4）当前格子可以从上方或者右边来，则dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
同时，不需要额外建立dp数组，直接在grid上修改，因为经历过的grid位置不会再被访问到。
*/

// 参考
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0)
                // 起始格子
                    continue;
                else if (i == 0)
                // 只能从右边来
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if (j == 0)
                // 只能从上方来
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                else
                // 其他情况
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

// wrong answer
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 总步数是长+宽-1
        int height = grid.size();
        int width = grid[0].size();
        int n = grid.size() + grid[0].size() - 1;
        vector<int> cost(n + 1);                            // 记录走了第n步的开销
        vector< vector<int> > pos(n + 1, vector<int>(2));     // 记录第n步的位置
        // 初始化开销数组
        cost[0] = 0; cost[1] = 1;
        // 初始化位置记录数组
        pos[0][0] = 0; pos[0][1] = 0;   pos[1][0] = 0; pos[1][1] = 0;
        for (int i = 1; i <= n; i++) {
            // 如果向右向下都能走
            if (pos[i - 1][0] < height - 1 && pos[i - 1][1] < width - 1) {
                if (grid[pos[i - 1][0] + 1][pos[i - 1][1]] < grid[pos[i - 1][0]][pos[i - 1][1] + 1]) {
                    cost[i] = cost[i - 1] + grid[pos[i - 1][0] + 1][pos[i - 1][1]];
                    pos[i][0] = pos[i - 1][0] + 1;
                    pos[i][1] = pos[i - 1][1];
                }
                else {
                    cost[i] = cost[i - 1] + grid[pos[i - 1][0]][pos[i - 1][1] + 1];
                    pos[i][0] = pos[i - 1][0];
                    pos[i][1] = pos[i - 1][1] + 1;
                }
            }
            // 如果向右不能走，向下能走
            else if (pos[i - 1][0] == height - 1 && pos[i - 1][1] < width - 1) {
                cost[i] = cost[i - 1] + grid[pos[i - 1][0]][pos[i - 1][1] + 1];
                pos[i][0] = pos[i - 1][0];
                pos[i][1] = pos[i - 1][1] + 1;
            }
            // 如果向右能走，向下不能走
            else if (pos[i - 1][0] < height - 1 && pos[i - 1][1] == width - 1) {
                cost[i] = cost[i - 1] + grid[pos[i - 1][0] + 1][pos[i - 1][1]];
                pos[i][0] = pos[i - 1][0] + 1;
                pos[i][1] = pos[i - 1][1];
            }
            // 向右向下都不能走（结束）
            else {
                cost[i] = cost[i - 1];
            }
        }
        return cost[n];
    }
};