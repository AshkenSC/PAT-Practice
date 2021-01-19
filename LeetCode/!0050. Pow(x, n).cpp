/*
0050. Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

思路：采用递归，快速幂。

参考：https://leetcode-cn.com/problems/powx-n/solution/cdi-gui-fang-fa-ji-bai-100ti-jiao-by-zhu-ij8e/

*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double half = myPow(x, N / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return half * half * x;
        }
    }
};
