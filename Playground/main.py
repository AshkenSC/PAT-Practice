# 198

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # dp = [[-prices[0], 0, 0]] + [[0, 0, 0]] * (n - 1)
        # 不能这样写！这样写修改某一行某元素，其他行对应元素也会修改！！！
        dp = [[-prices[0], 0, 0]] + [0] * (n - 1)
        for i in range(1, n):
            # 第i天手中持有股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i])
            # 第i天处于冷冻期
            dp[i][1]  = dp[i - 1][0] + prices[i]
            # 第i天手中没有股票
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2])
        
        return max(dp[n-1][1], dp[n-1][2])



sol = Solution()
res = sol.maxProfit([1,2,3,0,2])
print(res)