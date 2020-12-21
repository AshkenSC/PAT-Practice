/*
0509. Fibonacci Number

斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。

思路：递归，递推公式。
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;
    int res = sol.fib(5);
    cout << res;
    return 0;
}