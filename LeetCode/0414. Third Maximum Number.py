'''
0414. Third Maximum Number

给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

思路1：先用set取集合去重，再取第三大的。其实这个是不对的，因为排序的话，时间复杂度大于O（n)
思路2：用三个变量保存前三大的。主要是困惑在一开始三个变量初始值如何设置。要注意去重!!
'''
from typing import List

class Solution1:
    def thirdMax(self, nums: List[int]) -> int:
        nums_set = sorted(list(set(nums)))
        if len(nums_set) < 3:
            return max(nums_set)
        else:
            return nums_set[-3]


class Solution2:
    def thirdMax(self, nums: List[int]) -> int:
        first_max = float("-inf")
        second_max = float("-inf")
        third_max = float("-inf")
        for num in nums:
            # 跳过重复数，这个很关键
            if num == first_max or num == second_max  or num == third_max:
                continue
            if num > first_max:
                third_max = second_max
                second_max = first_max
                first_max = num
            elif num > second_max:
                third_max = second_max
                second_max = num
            elif num > third_max:
                third_max = num

        if third_max == float("-inf"):
            return first_max
        else:
            return third_max


sol = Solution()
print(sol.thirdMax([2, 2, 3, 2]))
