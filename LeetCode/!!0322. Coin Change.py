'''
0322. Coin Change

给定不同面额的硬币 coins 和一个总金额 amount。
编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。

思路：动态规划

首先初始化dp元素为INT MAX，
dp[i] = min(dp[i - coins[j]]) + 1
（如果i - coins[j]是负数，直接跳过）

最后如果dp[n]是INT MAX，返回-1，
如果不等于INT MAX，说明有解，返回dp[n]。
'''

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            prev_candidate = float('inf')
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] < prev_candidate:
                    prev_candidate = dp[i - coin]
            dp[i] = prev_candidate + 1
        
        if dp[amount] < float('inf'):
            return dp[amount]
        else:
            return -1


