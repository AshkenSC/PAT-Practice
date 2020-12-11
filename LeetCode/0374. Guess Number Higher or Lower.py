'''
0374. Guess Number Higher or Lower

猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。

思路：基础二分法。
'''

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left = 0
        right = n
        while left < right:
            # 为避免溢出，必须如此计算
            num = int(right - (right - left) / 2)
            status = guess(num)
            # pick == num
            if status == 0:
                return num
            # pick > num
            elif status == 1:
                left = num + 1
            # pick < num
            elif status == -1:
                right = num
        return left