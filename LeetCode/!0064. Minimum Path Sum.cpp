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
*/

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