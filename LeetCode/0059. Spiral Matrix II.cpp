/*
0059. Spiral Matrix II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

思路：参考解答https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/
分为从左到右，从上到下，从右到左，从下到上，四个部分，每个部分设定边界，每次都要更新边界。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, up = 0, down = n - 1;
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n));
        while (num <= n * n) {
            for (int i = left; i <= right; i++) {
                res[up][i] = num;
                num++;
            }
            up++;

            for (int i = up; i <= down; i++) {
                res[i][right] = num;
                num++;
            }
            right--;

            for (int i = right; i >= left; i--) {
                res[down][i] = num;
                num++;
            }
            down--;

            for (int i = down; i >= up; i--) {
                res[i][left] = num;
                num++;
            }
            left++;
        } 
        return res;
    }
};