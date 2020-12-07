/*
0130. Surrounded Regions

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

思路：bfs
这里需要注意那些延申到边界的O区域。比如：
XXXOX
XXOOX
XOOOX
XXXXX
根据规则，这种区域就不能被消除。

可以考虑先绕一圈把周围区域走完。然后再走中间区域。

又因为小细节debug了很久！注意。
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int row, col;
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    bool inArea(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < col)
            return true;
        else
            return false;
    }

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& walked, bool doMark, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(pair<int, int>(i, j));
        // 入队后，如果需要标记，则标为X，还要记录walked为true
        walked[i][j] = true;
        // 细节！这里也要注意判断！不然边缘的O会被误标为X
        if (doMark)
            board[i][j] = 'X';

        while (q.empty() == false) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            for (auto d : directions) {
                int nextX = curX + d[0];
                int nextY = curY + d[1];
                if (inArea(nextX, nextY) && !walked[nextX][nextY] && board[nextX][nextY] == 'O') {
                    q.emplace(pair<int, int>(nextX, nextY));
                    walked[nextX][nextY] = true;
                    if (doMark)
                        board[nextX][nextY] = 'X';
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        row = board.size();
        // 力扣不讲武德，搞空输入，来偷袭
        if (row == 0)
            return;
        col = board[0].size();

        vector< vector<bool> > walked(row, vector<bool>(col, false));

        // 检查所有边界，以及接壤边界的O区域
        for (int j = 0; j < col; j++) {
            // 扫描上边界
            // 如果在边界发现O，则将O所在的整个区域都走过一次
            walked[0][j] = true;
            if (board[0][j] == 'O') {
                bfs(board, walked, false, 0, j);
            }

            // 扫描下边界
            // 如果在边界发现O，则将O所在的整个区域都走过一次
            walked[row - 1][j] == true;
            if (board[row - 1][j] == 'O') {
                bfs(board, walked, false, row - 1, j);
            }
        }
        for (int i = 1; i < row - 1; i++) {
            // 左边界
            walked[i][0] = true;
            if (board[i][0] == 'O') {
                bfs(board, walked, false, i, 0);
            }
            // 右边界
            walked[i][col - 1] = true;
            if (board[i][col - 1] == 'O') {
                bfs(board, walked, false, i, col - 1);
            }
        }

        // 遍历中心，标记X
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (walked[i][j] == false && board[i][j] == 'O')
                    bfs(board, walked, true, i, j);
            }
        }

        return;
    }
};
