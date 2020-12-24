# 198

from typing import List


class Solution:
    def isUgly(self, num: int) -> bool:
        while num % 2 == 0:
            num /= 2
        while num % 3 == 0:
            num /= 3
        while num % 5 == 0:
            num /= 5
        if num == 1:
            return True
        else:
            return False


sol = Solution()
res = sol.maxProfit([1,2,3,0,2])
print(res)