'''
0070. Climbing Stairs

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

思路：设到达第n个台阶一共有dp(n)种方法。
则dp[0] = 0, dp[1] = 1
dp[n] = dp[n - 1] + dp[n - 2]
因为第n级台阶可能从第n-1走1步上来，或者从第n-2走两步上来。

尝试了递归写法，但输入38时超出时间限制了。
下面是用dp数组存储。
第二种方法是仅使用三个变量存储。
'''

# dp数组存储
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 1
        else:
            dp = [1, 1]
            i = 2
            while i <= n:
                dp.append(dp[i - 1] + dp[i - 2])
                i += 1
            return dp[-1] 

# 仅用三个变量存储
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 1
        else:
            dpN_1 = 1
            dpN_2 = 1
            i = 2
            while i <= n:
                dpN = dpN_1 + dpN_2
                i += 1
                dpN_2 = dpN_1
                dpN_1 = dpN
            return dpN