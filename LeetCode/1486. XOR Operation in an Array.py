# 1486. XOR Operation in an Array


class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = list()
        for i in range(n):
            nums.append(start + 2 * i)

        output = nums[0]
        for i in range(1, len(nums)):
            output = output ^ nums[i]

        return output


# # test
# solution = Solution()
# print(solution.xorOperation(10, 5))
