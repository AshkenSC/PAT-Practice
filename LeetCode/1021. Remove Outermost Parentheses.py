# 1021. Remove Outermost Parentheses
'''
变量count保存左括号数-右括号数。即遇到左括号则自增1，遇到右括号则自减1。
当count为0的时候，说明在这一段中左括号和右括号相等，是个完美匹配的括号串。
变量prev保存的是上一次括号完全匹配之后，下一个括号匹配开始位置。
当count==0的时候，结果增加的是[prev + 1, i)
'''


class Solution(object):
    def removeOuterParentheses(self, S):
        output = ''
        count = 0
        prev_part_end = 0
        for i in range(len(S)):
            if S[i] == '(':
                count += 1
            else:
                count -= 1
            if count == 0:
                if i - prev_part_end > 1:
                    output += S[prev_part_end + 1:i]
                prev_part_end = i + 1
                count = 0

        return output


# sol = Solution()
# res = sol.removeOuterParentheses("(()())(())(()(()))")
# print(res)



