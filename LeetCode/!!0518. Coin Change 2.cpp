/*
0518. Coin Change 2

给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

思路：动态规划。
注意本题和爬楼梯问题的区别！本题是组合，但爬楼梯是排列！
注意二层嵌套循环的顺序！

精选评论，总结的不错：
写的很好。一开始我也是想到爬楼梯那道题但是把自己绕晕了。 
看完文章后顿悟组合问题其实是在每一次for coin in coins循环中就把coin的可使用次数规定好了。
不允许在后面的硬币层次使用之前的硬币。 
这就像排列中2,2,1; 2,1,2是两种情况，但是组合问题规定好了一种书写顺序，
比如大的写在前面那就只有2,2,1这一种情况了。

参考网址：https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
