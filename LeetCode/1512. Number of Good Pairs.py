# 1512. Number of Good Pairs
'''
首先用一个字典，统计所有nums中出现过的数字他们的出现次数。
然后遍历这个字典，对于出现次数>=2的数字，如果出现了n次，那么就共有(n-1) + (n-2) + ... + 1对。
'''

from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        # 用字典存储所有出现过的数和出现过的位置
        occurs = dict()
        output = 0
        for i in range(len(nums)):
            if nums[i] not in occurs.keys():
                occurs[nums[i]] = 1
            else:
                occurs[nums[i]] += 1
        for number in occurs.keys():
            if occurs[number] >= 2:
                # 如果出现了n次，那么就共有(n-1) + (n-2) + ... + 1对
                n = occurs[number]
                output += int((n-1 + 1) * (n - 1) / 2)
        return output


# # test
# sol = Solution()
# ans = sol.numIdenticalPairs([1,2,3])
# print(ans)