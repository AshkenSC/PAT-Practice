'''
0394. Decode String

给定一个编码的字符串，返回他解码后的字符串。
编码规则是k[encoded_string]，其中encoded_string会被重复k次。注意到k保证是一个正整数。
可以假定输入字符串总是有效的，没有额外空格，方括号总是符合要求，等等。
此外，你也可以假定所有原始数据不包含数字，数字仅仅为表示重复次数k。例如不会有诸如3a和2[4]的输入。

思路：构建辅助栈

参考https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/

当前c是数字时，将数字字符转为数字multi，用于后续倍数计算；
当前c时字母时，在res尾部添加c
当c为[时，将当前multi和res入栈，并分别置0
当c为]时，stack出栈，拼接字符串res = last_res + cur_multi * res
返回字符串res
'''


class Solution:
    def decodeString(self, s: str) -> str:
        stack, res, multi = [], '', 0
        for c in s:
            if c == '[':
                stack.append([multi, res])
                res, multi = '', 0
            elif c == ']':
                # 获取当前的重复次数，和上一次的字符串结果
                cur_multi, last_res = stack.pop()
                # 将上一次的字符串结果和当前字符*重复次数拼接
                res = last_res + cur_multi * res
            elif '0' <= c <= '9':
                # 这样可以将连续多位数字转化为整数数值
                multi = multi * 10 + int(c)
            else:
                res += c
        return res
