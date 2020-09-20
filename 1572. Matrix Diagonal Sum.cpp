/*
1572. Matrix Diagonal Sum

计算一个矩阵左右对角线之和。
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int len = mat.size();
        for (int i = 0; i < len; i++) {
            res += mat[i][i];
        }
        for (int i = len - 1; i >= 0; i--) {
            res += mat[i][len - 1 - i];
        }
        if (len % 2 == 1) {
            res -= mat[(len - 1) / 2][(len - 1) / 2];
        }
        return res;
    }
};