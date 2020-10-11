/*
0054. Spiral Matrix

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

思路：参考https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/

1）设定上下左右边界
2）用四个循环依次向右、下、左、上移动。每次移动的范围由1）中的上下左右边界确定
3）移动完之后，进行边界缩小，并判断缩小后边界是否交叉。如果交叉则立即结束移动，返回结果
4）如果没有交叉，则重复2）3）步直到边界交叉
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true) {
            //　向右移动到最右
            for (int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            if (++up > down)
                break;
            
            // 向下移动到最下
            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            if (--right < left)
                break;

            // 向左移动到最左
            for (int i = right; i >= left; i--)
                res.push_back(matrix[down][i]);
            if (--down < up)
                break;
            
            // 向上移动到最上
            for (int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return res;
    }
};