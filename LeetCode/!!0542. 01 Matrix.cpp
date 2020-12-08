/*
0542. 01 Matrix

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。

思路：
正确解法：
1）BFS，参考官方解答。
2）动态规划，参考官方解答。

我的错误解法：
首先找到一个为0的位置，然后将格子入队，从这个位置开始BFS。
在队列不为空时执行循环：
队头出队；
将其周围格子入队（注意判断出界），入队的同时填写周围格子的取值。
    0）入队同时注意将格子标记为walked
    1）周围格子是0，直接赋值0；
    2）周围格子是1，根据情况：
        2.1）如果当前格子是0，则赋值1；
        2.2）如果当前格子是1，则赋值当前格子+1；

错在哪？我不该只找一个0格子就只将其入队。这样并不是所有的1格子都是从它最近的0格子处得到。
错例：
输入：
010
010
010

我的输出：
010
020
030

*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int row, col;
    vector<vector<int>> res;
    vector<vector<int>> walked;
    vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    bool inArea(int x, int y) {
        if (x >= 0 && x < row && y >= 0 && y < col)
            return true;
        else
            return false;
    }

    void bfs(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        // 将所有0格子入队系列操作
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(pair<int, int>(i, j));
                    walked[i][j] = 1;
                    res[i][j] = 0;
                }

            }
        }
            
        int currentX, currentY, nextX, nextY;
        while (q.empty() == false) {
            currentX = q.front().first;
            currentY = q.front().second;
            q.pop();

            // 检查四周格子
            for (auto d : directions) {
                nextX = currentX + d[0];
                nextY = currentY + d[1];
                // 如果四周格子没出界、没走过
                if (inArea(nextX, nextY) && !walked[nextX][nextY]) {
                    // 入队
                    q.emplace(pair<int, int>(nextX, nextY));
                    walked[nextX][nextY] = 1;
                    // 将四周格子设为当前格子距离+1
                    res[nextX][nextY] = res[currentX][currentY] + 1;

                    // 如果周围格子是0，直接赋值为0（事先填充就是0不用赋值了）
                    // ----

                    // 如果周围格子是1，当前格子是0，则赋值1；
                    if (matrix[nextX][nextY] == 1 && matrix[currentX][currentY] == 0)
                        res[nextX][nextY] = 1;
                    // 如果周围格子是1，当前格子是1，则赋值当前格子+1；
                    // 这个是不对的，如果周围格子附近有0怎么办呢？所以这个无法得到正确解答
                    else if (matrix[nextX][nextY] == 1 && matrix[currentX][currentY] == 1)
                        res[nextX][nextY] = res[currentX][currentY] + 1;

                }
            }
        }

    } 

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();

        walked.resize(row);
        res.resize(row);
        for (int i = 0; i < row; i++) {
            walked[i].resize(col);
            res[i].resize(col);
        }
    
        // BFS得到结果
        bfs(matrix);

        return res;
    }
};
