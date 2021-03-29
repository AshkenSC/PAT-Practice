/*
剑指 Offer 62. 圆圈中最后剩下的数字

0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，
每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
求出这个圆圈里剩下的最后一个数字。

思路：
参考解答：
https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/
*/

class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + m) % i;
        } 
        return res;
    }
};
