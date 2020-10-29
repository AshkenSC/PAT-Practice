'''
1365. How Many Numbers Are Smaller Than the Current Number
'''

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums_sort = sorted(list(nums))
        res = list()
        for num in nums:
            res.append(nums_sort.index(num))
        return res