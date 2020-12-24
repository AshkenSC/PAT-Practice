# 0309. Best Time to Buy and Sell Stock with Cooldown
# 注意Python二维数组的声明！！！

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # dp = [[-prices[0], 0, 0]] + [[0, 0, 0]] * (n - 1)
        # 不能这样写！这样写修改i行j列的元素时，其他行的j列元素也会修改！！！
        dp = [[-prices[0], 0, 0]] + [0] * (n - 1)
        for i in range(1, n):
            # 第i天手中持有股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i])
            # 第i天处于冷冻期
            dp[i][1]  = dp[i - 1][0] + prices[i]
            # 第i天手中没有股票
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2])
        
        return max(dp[n-1][1], dp[n-1][2])

