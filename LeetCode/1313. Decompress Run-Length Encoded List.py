# 1313. Decompress Run-Length Encoded List

from typing import List


class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        # 将输入数据整理为字典
        arrange = dict()
        i = 0
        while i < len(nums):
            freq = nums[i]
            val = nums[i + 1]
            i += 2
            arrange[val] = freq
        # 输出结果
        decompressed = list()
        for val in arrange.keys():
            for i in range(arrange[val]):
                decompressed.append(val)

        return decompressed


# test
sol = Solution()
print(sol.decompressRLElist([73,95,5,68,6,14,98,3,98,39,100,69,76,77,93,46,91,69,26,13,30,53,15,53,34,17]))
