'''
0665. Non-decreasing Array

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

思路：初步思路是判断，遍历数组，初始count = 0，如果当前元素值比它上一个元素值小，则count += 1，当count > 1时，直接返回false。
但是这种思路无法处理一种特殊情况：[3, 4, 2, 3]这一类。
假设当前i = 2，也就是a[i] < a[i - 2]，且a[i + 1] < a[i - 1]这个情形。这时可以直接返回false
'''

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                if i+1 < len(nums) and i-2 >= 0:
                    if nums[i] < nums[i - 2] and nums[i + 1] < nums[i - 1]:
                        return False
                cnt += 1
        if cnt > 1:
            return False
        else:
            return True
