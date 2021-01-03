'''
0062. Unique Paths

'''

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
        
        return dp[m - 1][n - 1]
        