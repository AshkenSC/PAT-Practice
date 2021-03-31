/*
剑指 Offer 64. 求1+2+…+n

求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

思路：
第一步，要想到能使用递归；
第二步，如何终止递归？使用逻辑运算符的“短路效应”。
即：如果运算符通过前半部分已经可以判断出结果，就不会再执行后半部分
例如A || B，如果A为真，不会再看B
例如A && B，如果A为假，不会再看B
*/

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
