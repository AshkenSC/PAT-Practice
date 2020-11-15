'''
0238. Product of Array Except Self

给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

思路：结果数组长度为n，记作res
首先，从左向右遍历数组，在res中记录每个数左边所有数字的乘积。
从右向左遍历数组，一边用right_product记录每个数字右边的所有数字乘积。
一边将其和res每个对应元素相乘。
'''

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 保存结果
        res = list()

        # 记录所有数左边的乘积
        res.append(1)
        for i in range(1, len(nums)):
            res.append(res[i - 1] * nums[i - 1])
          
        right_product = 1   # 记录数右边的乘积
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= right_product
            right_product *= nums[i]
        
        return res
                