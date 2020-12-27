# 198
'''
/*
dp[0] = 0
dp[i] = min(dp[i - coins[j]]) + 1

dp[0] = 0
dp[1] = 1
dp[2] = min(dp[1], dp[0], dp[-3]) + 1 = 1
dp[3] = min(dp[2], dp[1], dp[-2]) + 1 = 2
dp[4] = min(dp[3], dp[2], dp[-1]) + 1 = 2
dp[5] = min(dp4, dp3, dp0) + 1= 1
dp[6] = min(dp5, dp4, dp1) + 1= 2
dp[7] = min(dp6, dp5, dp2) + 1=2
dp8 = min(dp7, dp6, dp3) + 1 = 3
dp9 = min()
*/
'''

from typing import List

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



sol = Solution()
res = sol.coinChange([2], 3)
print(res)