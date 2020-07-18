# 1464. Maximum Product of Two Elements in an Array
'''
事实上就是找到数组里最大的两个数，将他们分别减1后相乘
'''
from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        return (nums[0] - 1) * (nums[1] - 1)


# sol = Solution()
# res = sol.maxProduct([3,4,5,2])
# print(res)