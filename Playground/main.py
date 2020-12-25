# 198

from typing import List


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_set = [1]
        i2 = 0
        i3 = 0
        i5 = 0
        while len(ugly_set) < 1690:
            new_ugly = min(ugly_set[i2] * 2, ugly_set[i3] * 3, ugly_set[i5] * 5)
            ugly_set.append(new_ugly)
            # if new_ugly not in ugly_set:
            #     ugly_set.append(new_ugly)
            if new_ugly == ugly_set[i2] * 2:
                i2 += 1
            elif new_ugly == ugly_set[i3] * 3:
                i3 += 1
            elif new_ugly == ugly_set[i5] * 5:
                i5 += 1

        return ugly_set[n - 1]
            

sol = Solution()
res = sol.nthUglyNumber(10)
print(res)