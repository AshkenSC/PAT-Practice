/*
剑指 Offer 65. 不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

思路：
将加法分为两部分：1）用xor去计算完全不考虑进位的相加；2）用and计算各位的进位情况（and后需要左移）；
然后将这两部分的结果用xor进一步相加，并进一步用and计算进位情况；
不断循环，直到第2）部分完全为0为止。

注意，使用c++时，对于第2）部分，需要强制转为unsigned int进行循环左移。否则会报错。

参考：
https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
以及下方C++的评论。
*/

class Solution {
public:
    int add(int a, int b) {
       int sumWithoutCarry = a, carry = b;
       while (carry != 0) {
           int carry_temp = (unsigned int)(sumWithoutCarry & carry) << 1;
           sumWithoutCarry = sumWithoutCarry ^ carry;
           carry = carry_temp;
       }
       return sumWithoutCarry;
    }
};
