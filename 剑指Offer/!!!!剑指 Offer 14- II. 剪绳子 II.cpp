/*
剑指 Offer 14- II. 剪绳子 II

其实应该不是很难，但是没睡好，看了一晚上没看懂快速幂，暂时放过他……
搞懂了为什么绳子尽可能取3。搞懂了贪心算法。
动态规划不能使用了，因为会超出范围。

参考：先参考第一个链接搞懂了为什么取3能得最大值；再参考第二个写的贪心。

https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/

https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/zhao-zhe-dao-ti-de-ben-zhi-by-lui-6/
*/

class Solution {
public:
    int cuttingRope(int n) {
       if (n == 2)  return 1;
       if (n == 3)  return 2;
       if (n == 4)  return 4;

       long res = 1;
       while (n > 4) {
           // 每次循环，截取长度为3的一小节。
           // 这样，结果不断乘以3，剩余绳子不断减少3
           res = res * 3;
           res %= 1000000007;
           n -= 3;
       }

       return (int)(res * n % 1000000007);
    }
};
