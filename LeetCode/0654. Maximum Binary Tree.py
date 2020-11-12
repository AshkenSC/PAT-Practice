'''
0654. Maximum Binary Tree

给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点

思路：
利用不含重复元素这一点。并进行递归构建
每次找到当前数组中最大元素，
其左、右子树的根节点是该元素左右子数组的最大元素。
由于每次都要找最大值，因此时间复杂度是O(n^2)。
'''

from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def build(self, nums):
        if len(nums) == 0:
            return None
        head = TreeNode(max(nums))
        max_pos = nums.index(max(nums))
        head.left = self.build(nums[0:max_pos])
        head.right = self.build(nums[max_pos+1:])
        return head

    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        return self.build(nums)