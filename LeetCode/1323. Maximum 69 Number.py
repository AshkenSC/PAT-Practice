'''
1323. Maximum 69 Number

给你一个仅由数字 6 和 9 组成的正整数 num。
你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。
请返回你可以得到的最大数字。

思路：翻转第一个出现的6.
'''

class Solution:
    def maximum69Number (self, num: int) -> int:
        num_str = str(num)
        res = 0
        is_changed = False
        for digit in num_str:
            if digit == '6' and is_changed is False:
                res = res * 10 + 9
                is_changed = True
            else:
                res = res * 10 + int(digit)
        return res