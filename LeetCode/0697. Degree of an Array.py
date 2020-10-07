'''
0697. Degree of an Array

本题还需要学习一些Python写法技巧。

思路：对于给定数组中的每个元素， left 是它第一次出现的索引； right 是它最后一次出现的索引。
例如，当 nums = [1,2,3,2,5] 时，left[2] = 1 和 right[2] = 3。

然后，对于出现次数最多的每个元素 x，right[x] - left[x] + 1 将是候选答案，取这些候选的最小值。

'''

from typing import List

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        left = dict()
        right = dict()
        count = dict()
        for i, num in enumerate(nums):
            # 如果num还不在left（记录数字最早出现的下标里），记录它
            if num not in left:
                left[num] = i
            # 不断更新num最后出现的位置
            right[num] = i
            # 不断更新num出现的次数
            count[num] = count.get(num, 0) + 1

        ans = len(nums)
        degree = max(count.values())
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)

        return ans


sol = Solution()
print(sol.findShortestSubArray([1,2,2,3,1]))
