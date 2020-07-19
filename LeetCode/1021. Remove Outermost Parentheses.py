# 1021. Remove Outermost Parentheses
'''
变量count保存左括号数-右括号数。即遇到左括号则自增1，遇到右括号则自减1。
当count为0的时候，说明在这一段中左括号和右括号相等，是个完美匹配的括号串。
变量prev保存的是上一次括号完全匹配之后，下一个括号匹配开始位置。
当count==0的时候，结果增加的是[prev + 1, i)
'''

class Solution(object):
    def removeOuterParentheses(self, S):
        prev = 0
        output = ""
        count = 0
        for i, s in enumerate(S):
            if s == '(':
                count += 1
            else:
                count -= 1
            if count == 0:
                output += S[prev + 1: i]
                prev = i + 1
        return output

