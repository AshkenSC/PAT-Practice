'''
0046. Permutations

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

思路：回溯法，参考：
https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/

自己写的，有一个地方有问题：就是应该用一个数组used，记录数字是否用过。其他和参考答案思路基本一致。
'''

from typing import List


class Solution:
    def backtrack(self, nums, used, curPermutation, res):
        # 当前序列的长度等于所有候选数字的个数
        if (len(curPermutation) == len(nums)):
            res.append(curPermutation.copy())
            return
        # 当前序列长度不足，继续找组合
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                curPermutation.append(nums[i])
                # 递归找排列
                self.backtrack(nums, used, curPermutation, res)
                # 回溯
                used[i] = False
                curPermutation.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        curPermutation = []
        # used列表，用于记录nums中数字是否被使用了
        used = [False for _ in range(len(nums))]
        self.backtrack(nums, used, curPermutation, res)
        return res
