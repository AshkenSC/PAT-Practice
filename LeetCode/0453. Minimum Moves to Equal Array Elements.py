'''
0453. Minimum Moves to Equal Array Elements

给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动将会使 n - 1 个元素增加 1。

思路：每次移动使得n-1个元素增加1，也就是每次同时让n个元素增加1，再让1个元素-1
也就是，只要找到，每次让一个元素-1，经过多少次操作，所有元素相等，即可。
那也就是找到数组的最小值，然后遍历所有元素，对每个元素，都需要进行“与最小值的差”次操作，才行。
'''

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        res = 0
        nums.sort()
        for i in range(len(nums)):
            res += nums[i] - nums[0]
        return res