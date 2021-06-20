'''
0034. Find First and Last Position of Element in Sorted Array

给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。

思路：
二分法典例！！
进行两次二分查找，分别找到起点和终点。
找到起点和终点的思路参考：
https://www.cnblogs.com/kyoner/p/11080078.html

'''

from typing import List


class Solution:
    def binary_search(self, nums, target, mode):
        if len(nums) == 0:
            return -1
        
        left = 0
        right = len(nums)

        if mode == 'left':
            while left < right:
                mid = int(right - (right - left) / 2)
                if nums[mid] == target:
                    right = mid
                elif nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid
            if left >= len(nums):
                return -1
            if nums[left] == target:
                return left
            else:
                return -1

        elif mode == 'right':
            while left < right:
                mid = int(right - (right - left) / 2)
                if nums[mid] == target:
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid
            if right < 1:
                return -1
            elif nums[right - 1] == target:
                return right - 1
            else:
                return -1
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.binary_search(nums, target, 'left')
        right = self.binary_search(nums, target, 'right')
        return [left, right]


sol = Solution()
res = sol.searchRange([1], 1)
print(res)
