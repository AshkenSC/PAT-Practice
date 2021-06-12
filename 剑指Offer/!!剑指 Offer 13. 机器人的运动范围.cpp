/*
剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

思路：
BFS。关键是要知道，虽然是走四个方向，但实际只需要考虑向右和向下。

参考：
https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/jian-zhi-offerer-shua-javadfs-bfs-tu-jie-py05/
*/


class Solution {
private:
    int getDigitSum(const int& num) {
        int sum = 0;
        string numStr = to_string(num);
        for (char c : numStr) {
            sum += c - '0';
        }
        return sum;
    }

public:
    int movingCount(int m, int n, int k) {
        int res = 0;
        // 创建visited数组记录是否走过
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        // 创建队列用于BFS
        queue<pair<int, int>> q;
        // 将起点入队
        q.emplace(pair<int, int>(0, 0));

        while (!q.empty()) {
            // 队头出队
            pair<int, int> head = q.front();
            int row = head.first, col = head.second;
            q.pop();

            // 检查队头是否合法，如果非法则跳过
            if (row >= m || col >= n || getDigitSum(row) + getDigitSum(col) > k || isVisited[row][col]) {
                continue;
            }

            // 如果队头合法，则入队其右边和下边格子，并增加计数
            ++res;
            isVisited[row][col] = true;
            q.emplace(pair<int, int>(row + 1, col));
            q.emplace(pair<int, int>(row, col + 1));
        }

        return res;
    }
};

