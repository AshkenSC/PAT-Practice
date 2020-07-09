# 1389. Create Target Array in the Given Order

'''
如果每次直接修改output数组，用时过长，考虑先研究index数组，将index数组变成最终nums的位置，然后最后一次性插入。
# 以index = [0,1,2,2,1]为例子，假设最后插入的为index1，变化情况如下：
[0]
[0,1]
[0,1,2]
[0,1,3,2]
[0,2,4,3,1]
可以发现，如果出现了前面出现过的数字k，那么前面所有大于等于k的数字，都要+1，最后在列表结尾加上k
'''


from typing import List


class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        # 初始化输出列表和最终index列表
        output = [-1] * len(nums)
        final_index = list()
        # 整理出最终index列表
        for element in index:
            if element not in final_index:
                final_index.append(element)
            else:
                for i in range(len(final_index)):
                    if final_index[i] >= element:
                        final_index[i] += 1
                final_index.append(element)

        # 根据final index填充output
        for i in range(len(nums)):
            output[final_index[i]] = nums[i]

        return output


# test
# sol = Solution()
# print(sol.createTargetArray([0,1,2,3,4], [0,1,2,2,1]))




