# 1313. Decompress Run-Length Encoded List

'''
每次读取两个数，并实时更新解压缩数组
运行速度较慢，有很大提升空间
第一版采用了将输入数据存为字典，再根据字典生成解压缩数组。
但是不能全通过，发现后面可能会出现重复的数字，这就导致覆盖了前面的键值对。
'''


from typing import List


class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        decompressed = list()
        arrange = dict()
        i = 0
        while i < len(nums):
            freq = nums[i]
            val = nums[i + 1]
            i += 2
            for j in range(freq):
                decompressed.append(val)

        return decompressed


# test
sol = Solution()
print(sol.decompressRLElist([1,2,3,4]))
