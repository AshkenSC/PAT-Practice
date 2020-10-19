'''
0227. Basic Calculator II

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

思路：参考https://leetcode-cn.com/problems/basic-calculator-ii/solution/zhan-by-elevenxx/
将算式看作是若干带符号数的和，例如3+5/2-4 看作是+3，+(5/2), -4的和
用一个变量存储当前数前面的符号。
遍历字符串，遇到数字就继续拼接当前数，直到遇到符号。
如果遇到加减还好说，遇到乘除，就将之前存的数出栈，和当前数做运算，结果存回列表。
注意，第一个数前面要补上一个加号。

'''

class Solution:
    def calculate(self, s: str) -> int:
        nums = list()
        
        current_num = ''
        sign = '+'
        for i in range(len(s)):
            # 遇到数字，拼接当前数
            if '0' <= s[i] <= '9':
                current_num += s[i]
            # s[i]遇到下一个运算符，开始将当前数连同符号加入nums中
            if s[i] in '+-*/' or i == len(s) - 1:
                if sign == '+':
                    nums.append(int(current_num))
                elif sign == '-':
                    nums.append(-int(current_num))
                elif sign == '*':
                    prev = nums.pop()
                    nums.append(prev * int(current_num))
                elif sign == '/':
                    prev = nums.pop()
                    nums.append(int(prev / int(current_num)))
                current_num = ''
                sign = s[i]
            
        return sum(nums)