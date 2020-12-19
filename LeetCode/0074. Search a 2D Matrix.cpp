/*
0074. Search a 2D Matrix

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

思路：二分法，用除法处理一下二维数组的两个index。

*/

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;

        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[mid / col][mid % col] == target) {
                return true;
            }
            else if (matrix[mid / col][mid % col] < target) {
                left = mid + 1;
            }
            else if (matrix[mid / col][mid % col] > target) {
                right = mid - 1;
            }
        }

        return false;
    }
};
