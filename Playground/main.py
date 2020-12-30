# 198
'''
dp[i][j][k]使用前i个物品，当背包容量为j个0，k个1时，能容纳的物品个数
dp[i][j][k] = max{dp[i - 1][j][k], dp[i - 1][j - strs[i][0]][k - strs[i][1]] + 1}
'''

from typing import List

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        pass

sol = Solution()
res = sol.coinChange([2], 3)
print(res)