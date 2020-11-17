'''
0279. Perfect Squares

'''

class Solution:
    def numSquares(self, n: int) -> int:
        # 初始化dp数组
        dp = []
        for i in range(n + 1):
            dp.append(i)

        # 逐步推导出最优dp
        # dp(i) = min{dp(i - j * j)} + 1
        for i in range(4, n + 1):
            j = 0
            min_sqr = float('inf')
            while (i - j * j >= 0):
                if dp[i - j * j] < min_sqr:
                    min_sqr = dp[i - j * j]
                j += 1
            dp[i] = min_sqr + 1
        
        return dp[n]