/*
0695. Max Area of Island

给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

思路：和200题完全一样。采用BFS。
但是很多小细节的疏忽导致debug了好几次！

*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxArea = 0;
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int row, col;

    bool inArea(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < col)
            return true;
        else
            return false;
    }

    int bfs(vector<vector<int>>& grid, int i, int j) {
        int currentArea = 1;
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(i, j));
        grid[i][j] = 0;

        while (q.empty() == false) {
            int currentX = q.front().first;
            int currentY = q.front().second;
            q.pop();
            for (auto d : directions) {
                int nextX = currentX + d[0];
                int nextY = currentY + d[1];
                if (inArea(nextX, nextY) && grid[nextX][nextY] == 1) {
                    q.emplace(pair<int, int>(nextX, nextY));
                    grid[nextX][nextY] = 0;
                    currentArea++;  // 累加面积
                }
            }
        }

        return currentArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};
