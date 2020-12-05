'''
0022. Generate Parentheses

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

思路：回溯法。要保证：
1）现有的左括号数量必须保持大于等于右括号数量；
2）最后的左右括号数量相等，等于n
'''

from typing import List

class Solution:
    def __init__(self) -> None:
        super().__init__()
        self.res = []
        self.cur_combination = ''

    def backtrack(self, n, left, right):
        if left == n and left == right:
            self.res.append(self.cur_combination)
            return
        # 增加左括号
        if left < n:
            self.cur_combination += '('
            self.backtrack(n, left + 1, right)
            # 回溯
            self.cur_combination = self.cur_combination[:-1]
        # 增加右括号
        if left > right:
            self.cur_combination += ')'
            self.backtrack(n, left, right + 1)
            # 回溯
            self.cur_combination = self.cur_combination[:-1]
            

    def generateParenthesis(self, n: int) -> List[str]:
        self.backtrack(n, 0, 0)
        return self.res
