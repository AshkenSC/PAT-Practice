'''
0241. Different Ways to Add Parentheses

给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。
你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

思路：
本质上，这道题就是输出所有运算符以不同顺序进行运算后的结果。
例如："2*3-4*5"，只看其中的运算符 *1，-2，*3，
那么可以排序，就有不同的结果：*1，-2，*3；*1，*3，-2；-2，*1，*3……等等。

所以，我们可以把数字放入队列，把运算符放入list中。
数字的顺序保持不变，运算符每次更换新的排列顺序。
然后依次按运算符的排列顺序进行计算。
'''

from typing import List


class Solution:
    def __init__(self):
        self.res = set()
        self.nums = []
        self.symbols = []
        self.symbol_permutation = []

    def load_exp(self, s):
        nums = []
        symbols = []

        sub_str = ''
        for char in s:
            if char in '+-*/':
                symbols.append(char)
                nums.append(int(sub_str))
                sub_str = ''
            else:
                sub_str += char
        nums.append(int(sub_str))

        return nums, symbols

    def calc(self, a, b, symbol):
        if symbol == '+':
            return a + b
        elif symbol == '-':
            return a - b
        elif symbol == '*':
            return a * b
        elif symbol == '/':
            return a / b

    # 按照symbol_permutation的顺序进行计算
    # TODO 有错误！
    def calculate(self):
        temp = self.nums.copy()
        # 每次提取symbol[i]和他左右两边的数字进行运算。运算结果再存放回temp中
        for i in range(len(self.symbol_permutation)):
            # TODO 有错，不能这样写，pop以后再放进去，索引值已经发生变化，无法取得你想要的数了
            a = temp.pop(i)
            b = temp.pop(i)            
            temp.insert(i, self.calc(a, b, self.symbols[i]))
        # 循环结束时，temp里只剩下一个数：最后计算结果
        return temp[0]

    def backtrack(self, start_index):
        # 所有运算符排列完毕，开始运算
        if len(self.symbol_permutation) == len(self.symbols):
            self.res.add(self.calculate())
            return
        # 运算符排列未完成
        else:
            for i in range(start_index, len(self.symbols)):
                self.symbol_permutation.append(i)
                self.backtrack(start_index)
                self.symbol_permutation.pop()

    def diffWaysToCompute(self, input: str) -> List[int]:
        # 将字符串读取为运算数列表和运算符列表
        self.nums, self.symbols = self.load_exp(input)
        # 将运算符做全排列，然后计算结果
        self.backtrack(0)

        return list(self.res)
        

sol = Solution()
res = sol.diffWaysToCompute("2-1-1")
print(res)