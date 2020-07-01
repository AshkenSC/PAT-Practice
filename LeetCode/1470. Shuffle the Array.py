# 1470. Shuffle the Array

from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        output = list()
        # 设置两个指针，指向x1, y1
        x_pointer = 0
        y_pointer = n
        while x_pointer < n:
            output.append(nums[x_pointer])
            output.append(nums[y_pointer])
            x_pointer += 1
            y_pointer += 1

        return output


# # test
# nums = [1,2,3,4,4,3,2,1]
# solution = Solution()
# print(solution.shuffle(nums, int(len(nums)/2)))