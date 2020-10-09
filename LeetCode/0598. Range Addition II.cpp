/*
598. Range Addition II

给定一个初始元素全部为 0，大小为 m*n 的矩阵 M 以及在 M 上的一系列更新操作。
操作用二维数组表示，其中的每个操作用一个含有两个正整数 a 和 b 的数组表示，含义是将所有符合 0 <= i < a 以及 0 <= j < b 的元素 M[i][j] 的值都增加 1。
在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。

思路1：暴力解法。但是会超时。
思路2：观察发现，每次都是从左上角开始操作，因此被操作到的矩阵范围在左上角重叠。因此只需要找到a和b的最小值，求a*b即可。
*/

class Solution1 {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> mat(m, vector<int>(n));
        int currentMax = 0;
        // 进行一系列操作
        for (vector<int> opr : ops) {
            for (int i = 0; i < opr[0]; i++) {
                for (int j = 0; j < opr[1]; j++) {
                    mat[i][j]++;
                    // 更新当前最大值
                    if (mat[i][j] > currentMax)
                        currentMax = mat[i][j];
                }
            }
        }
        // 返回矩阵中含有最大整数的元素的个数
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == currentMax) {
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_a = m, min_b = n;
        for (vector<int> opr : ops) {
            if (opr[0] < min_a)
                min_a = opr[0];
            if (opr[1] < min_b)
                min_b = opr[1];
        }
        return min_a * min_b;
    }
};