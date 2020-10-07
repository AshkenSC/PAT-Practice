'''
0442. Find All Duplicates in an Array

给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。
你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

思路1：用长度为n+1的数组记录“还允许出现多少次”，每出现一次，对应位就-1.这样，第二次出现时，就为0，就知道是再次出现了。

思路2：不使用额外空间，那就只能修改原来的数组。由于1 ≤ a[i] ≤ n，因此访问过的数可改为负数，就不使用额外空间也能直到是再次访问了。

'''

from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        appear = [1] * (len(nums) + 1)
        res = list()
        for num in nums:
            if appear[num] < 1:
                res.append(num)
                continue
            else:
                appear[num] -= 1
        return res

sol = Solution()
print(sol.findDuplicates([4,3,2,7,8,2,3,1]))