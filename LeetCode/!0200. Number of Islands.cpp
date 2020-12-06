/*
0200. Number of Islands

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

思想：依次遍历整个网格，检查当前格子是否是岛屿且未被访问过。
如果是岛屿而且未被访问过，就使用dfs或者bfs一次性访问完所有相邻的且是岛屿的位置，标记为访问过
这样就把当前这个点所在岛屿的区域全部位置都访问了一遍了。同时岛屿计数+1。
这样依次遍历完所有的网格，就能数出岛屿个数。

https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int res = 0;
    // bfs方向：上，右，下，左
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int row, col;

    // 判断当前位置是否出格
    bool inArea(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < col)
            return true;
        else
            return false;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j] = '0';
        q.emplace(pair<int, int>(i, j));

        while (q.empty() == false) {
            int currentX = q.front().first;
            int currentY = q.front().second;
            q.pop();

            // 之前把这循环里本应写currentX，currentY的都写成了i，j！难怪错了
            for (auto d : directions) {
                if (inArea(currentX + d[0], currentY + d[1]) && grid[currentX + d[0]][currentY + d[1]] == '1') {
                    // 将要入队的（即将访问的岛屿位置）结点标为0
                    grid[currentX + d[0]][currentY + d[1]] = '0';
                    // 入队
                    q.emplace(pair<int, int>(currentX + d[0], currentY + d[1]));
                }
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

