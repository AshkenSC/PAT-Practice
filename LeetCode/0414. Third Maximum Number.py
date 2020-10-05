'''
0414. Third Maximum Number

给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

思路1：先用set取集合去重，再取第三大的。其实这个是不对的，因为排序的话，时间复杂度大于O（n)
思路2：用三个变量保存前三大的。主要是困惑在一开始三个变量初始值如何设置
'''
from typing import List

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums_set = sorted(list(set(nums)))
        if len(nums_set) < 3:
            return max(nums_set)
        else:
            return nums_set[-3]

sol = Solution()
print(sol.thirdMax([3,2,1]))