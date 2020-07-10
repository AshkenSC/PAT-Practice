# 1295. Find Numbers with Even Number of Digits

from typing import List


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        output = 0
        for num in nums:
            num_str = str(num)
            if len(num_str) % 2 == 0:
                output += 1

        return output


# # test
# sol = Solution()
# print(sol.findNumbers([555,901,482,1771]))
