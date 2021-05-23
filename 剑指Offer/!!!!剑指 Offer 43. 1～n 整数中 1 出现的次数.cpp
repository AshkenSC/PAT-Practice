/*
剑指 Offer 43. 1～n 整数中 1 出现的次数

输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

思路：
找规律问题，自己真想不出来。
参考：
https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/javadi-gui-by-xujunyi/
*/

class Solution {
private:
    int f(int n) {
        if (n <= 0) {
            return 0;
        }
        string s = to_string(n);
        int high = s[0] - '0';
        int power = pow(10, s.size() - 1);
        int last = n - high * power;
        if (high == 1) {
            return f(power - 1) + last + 1 + f(last);
        }
        else {
            return power + high * f(power - 1) + f(last);
        }
    }

public:
    int countDigitOne(int n) {
        return f(n);
    }
};
