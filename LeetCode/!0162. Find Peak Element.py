# 0162. Find Peak Element


from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = int(left + (right - left) / 2)
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left
            