'''
0189. Rotate Array

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
要求使用空间复杂度为 O(1) 的 原地 算法。

思路：
王道原题。
首先注意，向右移动k位置，等价于移动k mod n位置。
1）整体翻转数组；
2）翻转前k个数；
3）翻转后n - k个数

'''

class Solution:
    def reverse(self, array, start, end):
        end -= 1
        while start < end:
            temp = array[start]
            array[start] = array[end]
            array[end] = temp
            start += 1
            end -= 1
    
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        self.reverse(nums, 0, len(nums))
        self.reverse(nums, 0, k)
        self.reverse(nums, k, len(nums))
        
        