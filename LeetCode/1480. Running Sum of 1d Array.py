# 1480. Running Sum of 1d Array

from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        output = list()
        for i in range(1, len(nums) + 1):
            output.append(sum(nums[0:i]))
        return output


# # test
# solution = Solution()
# print(solution.runningSum([1, 1, 1, 1]))