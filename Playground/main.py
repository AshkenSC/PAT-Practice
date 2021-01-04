# 198
'''
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
（索引不能出界）

dp[i][j] = dp[i - 1][j] * obstacleGrid[i - 1][j] + dp[i][j - 1] * obstacleGrid[i][j - 1];


'''

from typing import List

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        
        for i in range(m):
            for j in range(n):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]


sol = Solution()
res = sol.coinChange([2], 3)
print(res)