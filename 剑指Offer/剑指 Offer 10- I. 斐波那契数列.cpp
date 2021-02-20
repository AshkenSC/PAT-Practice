/*
剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

本题的坑：f[2] = (f[0] + f[1]) % 1000000007;防止数字太大。

*/

class Solution {
public:
    int fib(int n) {
        vector<long long> f(3, 0);
        f[1] = 1; f[2] = 1;

        if (n < 3) {
            return f[n];
        }

        for (int i = 3; i <= n; ++i) {
            f[0] = f[1];
            f[1] = f[2];
            f[2] = (f[0] + f[1]) % 1000000007;
        }
        return f[2];
    }
};