'''
0078. Subsets

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

思路：实际上是回溯法求组合的变体。区别在于，这道题每次进入递归都要向res里添加当前结果，
而不仅仅是在全部取完候选数字后再存入res。
'''
from typing import List


class Solution:
    # cpp可以写在这里，但是py不行，力扣跑下一个测试不会清空这边上一次的记录
    # res = [[]]
    # chosen = []

    def backtrack(self, nums, start_index, res, chosen):
        res.append(chosen.copy())
        if (start_index == len(nums)):
            return
        # dfs遍历
        for i in range(start_index, len(nums)):
            chosen.append(nums[i])
            # dfs
            self.backtrack(nums, i + 1, res, chosen)
            # 回溯
            chosen.pop()


    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        chosen = []
        self.backtrack(nums, 0, res, chosen)
        return res
