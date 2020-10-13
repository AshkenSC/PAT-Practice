'''
1365. How Many Numbers Are Smaller Than the Current Number

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

思路：
定义数组dic存储每个数字出现的次数。
第一次遍历统计每个数字出现的次数。
第二次遍历统计对原数组的每个数n，从0到n一共出现了多少次，将这个数组作为结果数组。


'''

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        dic = [0]*101
        
        for n in nums:
            dic[n] += 1

        return [sum(dic[0:n]) for n in nums]
