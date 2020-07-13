# 0136. Single Number
'''
遍历数组，用字典存储元素出现过的次数。
'''

from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        occurs = dict()
        for num in nums:
            if num not in occurs.keys():
                occurs[num] = 1
            else:
                occurs[num] += 1
        for num in occurs:
            if occurs[num] == 1:
                return num


# test
sol = Solution()
ans = sol.singleNumber([4,1,2,1,2])
print(ans)