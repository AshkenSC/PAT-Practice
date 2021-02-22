/*
剑指 Offer 16. 数值的整数次方

实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

思路：快速幂。注意处理底数为0，或者指数为负数情况

参考：
https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        long b = n;
        double res = 1.0;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        
        while (b > 0) {
            if (b & 1 == 1) {
                res = res * x;
                x = x * x;
                b >>= 1;
            }
        }

        return res;
    
    }
};
