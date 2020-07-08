# 1365. How Many Numbers Are Smaller Than the Current Number


from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result = list()
        for num in nums:
            result.append(self.find_how_many_smaller(num, nums))
        return result

    def find_how_many_smaller(self, num, nums):
        smaller_count = 0
        for number in nums:
            if number < num:
                smaller_count += 1
        return smaller_count

