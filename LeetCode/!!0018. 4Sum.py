'''
0018. 4Sum

给定一个包含n 个整数的数组nums和一个目标值target，判断nums中是否存在四个元素 a，b，c和 d，使得a + b + c + d的值与target相等？找出所有满足条件且不重复的四元组。
注意：答案中不可以包含重复的四元组。

思路1：回溯法
参考https://leetcode-cn.com/problems/4sum/solution/hui-su-suan-fa-dfsjie-jue-suo-you-nshu-he-wen-ti-e/
个人方法，超时！而且花了很久才想出来。
'''

from typing import List

class Solution:

    def backtrack(self, nums, candidates, target, result, begin_id):
        temp = None  # 设置该变量用于解决同一深度的重复问题
        if len(candidates) == 4:
            if sum(candidates) == target:
                result.append(candidates.copy())
            return
        for i in range(begin_id, len(nums)):
            if temp != nums[i]:
                temp = nums[i]
                candidates.append(nums[i])
                self.backtrack(nums, candidates, target, result, i + 1)
                candidates.pop()

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        sorted_nums = sorted(nums)  # 将候选数排序，以便解决重复问题
        self.backtrack(sorted_nums, [], target, result, 0)
        return result


sol = Solution()
nums = [8376, 1, -1, 2, 3, 0]
print(sol.fourSum(nums, 8377))
