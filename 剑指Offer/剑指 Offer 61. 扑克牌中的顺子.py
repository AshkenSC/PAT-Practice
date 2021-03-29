'''
剑指 Offer 61. 扑克牌中的顺子

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

思路1：首先非有0和无0两种情况。对有0情况，看0能否填补非连续相邻两数之间的空隙。具体参看代码中的注释。
'''

class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        # 分为两种大情况，有0和无0
        # 无0
        if 0 not in nums:
            # 如果没有0，就要严格判断是否连续
            nums.sort()
            for i in range(1, len(nums)):
                if nums[i] != nums[i - 1] + 1:
                    return False
            return True
        # 有0   
        else:
            # 如果有0，就看用0能否填补数字的空缺
            nums.sort()
            zero_count = 0
            for i in range(len(nums)):
                if nums[i] == 0:
                    zero_count += 1
                else:
                    # 从第二个非0数字开始判断起
                    if nums[i - 1] != 0:
                        # 如果有相等非0数字不是顺子
                        if nums[i] == nums[i - 1]:
                            return False
                        # 如果相邻数的差超过1，需要用0来填补
                        elif nums[i] - nums[i - 1] > 1:
                            zero_count -= nums[i] - nums[i - 1] - 1
                    # 如果用以填补空缺的0超支了，则就不是顺子
                    if zero_count < 0:
                        return False
            return True
            
