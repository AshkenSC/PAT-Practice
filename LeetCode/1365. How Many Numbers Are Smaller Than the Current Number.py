'''
1365. How Many Numbers Are Smaller Than the Current Number

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

思路：将原来的数组排序（不去重），然后对原来列表中的每个数字，找到他在排序列表中第一次出现的位置。
'''

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums_sort = sorted(list(nums))
        res = list()
        for num in nums:
            res.append(nums_sort.index(num))
        return res