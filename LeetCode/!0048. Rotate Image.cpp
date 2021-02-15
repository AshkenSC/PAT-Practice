/*
0048. Rotate Image

给定一个n*n的2D矩阵，代表一张图片。将这个图片顺时针旋转90度。
要求必须就地旋转，也就是不能额外申请一个数组进行旋转。

思路：参考官方解答方法3。
观察矩阵可知，可先上下翻转，再左右翻转。
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 先上下翻转
        for (int i = 0; i < n / 2; ++i) {
            vector<int> temp = matrix[i];
            matrix[i] = matrix[n - 1 - i];
            matrix[n - 1 - i] = temp;
        }

        // 再沿着主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
