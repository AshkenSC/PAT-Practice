/*
剑指 Offer 29. 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

思路：做过但有些生疏。
1）忘记最外层循环的条件；
2）忘记内层分段打印时的数组元素index；
3）搞错了拐弯时边界变化后的判断条件。
*/

class Solution {
private:
    vector<int> res;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        // 忘记这里循环的条件了
        while (true) {
            for (int i = left; i <= right; ++i) {
                // 忘记这里第一维度应该写什么了
                res.push_back(matrix[up][i]);
            }
            // 这里判断条件里的大于号错写成大于等于
            if (++up > down) break;

            for (int i = up; i <= down; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) break;

            for (int i = right; i >= left; --i) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) break;

            for (int i = down; i >= up; --i) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }

        return res;
    }
};
