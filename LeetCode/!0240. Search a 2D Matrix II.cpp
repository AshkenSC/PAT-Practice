/*
0240. Search a 2D Matrix II

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

思路：从矩阵的右上角或者左下角开始。
因为这两个位置具有“又大又小”的属性：是一行中最大的，又是一列中最小的。
这样，假设从右上角开始。如果当前数比target大，可以向左走减小；如果比target小，可以向右走增大。

参考：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/hua-tu-jie-ti-sou-suo-er-wei-ju-zhen-ii-by-ji-jue-/
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int row = matrix.size(), col = matrix[0].size();
        int x = 0, y = col - 1;
        while (0 <= x && x < row && 0 <= y && y < col) {
            if (target == matrix[x][y])
                return true;
            else if (target > matrix[x][y]) {
                ++x;
            }
            else if (target < matrix[x][y]) {
                --y;
            }
        }

        return false;
    }
};
