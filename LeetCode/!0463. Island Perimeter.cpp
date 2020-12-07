/*
0463. Island Perimeter

给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
网格中的格子 水平和垂直 方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

思路：bfs。
首先，遍历定位到一块陆地，停下，然后进行bfs。
bfs的过程中，对于每一块陆地，查看其上下左右是水或者外域的边数，计算这块陆地所占用的边长。
就这样逐步累计计算边长，直到获取总边长。
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int res = 0;
    int row, col;
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    bool inArea(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < col)
            return true;
        else
            return false;
    }

    // 计算当前格子贡献多少边长
    int getGridPerim(vector<vector<int>>& grid, int x, int y) {
        int gridPerim = 0;

        for (auto d : directions) {
            int nextX = x + d[0];
            int nextY = y + d[1];
            // 如果next出界，这一边也算边长
            if (!inArea(nextX, nextY)) {
                gridPerim++;
            }
            // 如果next不出界，但是水，这一边也算边长
            else {
                if (grid[nextX][nextY] == 0) {
                    gridPerim++;
                }
            }
        }

        return gridPerim;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& walked, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(i, j));
        walked[i][j] = true;
        res += getGridPerim(grid, i, j);

        while (q.empty() == false) {
            int currentX = q.front().first;
            int currentY = q.front().second;
            q.pop();
            for (auto d : directions) {
                int nextX = currentX + d[0];
                int nextY = currentY + d[1];
                // 广度遍历没走过且为陆地的四周，注意检查是否出界
                if (inArea(nextX, nextY) && grid[nextX][nextY] == 1 && !walked[nextX][nextY]) {
                    q.emplace(pair<int, int>(nextX, nextY));
                    walked[nextX][nextY] = true;
                    // 计算这块陆地贡献的边长
                    res += getGridPerim(grid, nextX, nextY);
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        vector<vector<bool>> walked(row, vector<bool>(col, false));

        // 先找到一块陆地，然后开始bfs
        int i, j;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, walked, i, j);
                    return res;
                }
                
            }
        }
        return res;
    }
};

