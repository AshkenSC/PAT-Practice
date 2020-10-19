'''
150. Evaluate Reverse Polish Notation

根据 逆波兰表示法，求表达式的值

思路：用栈存储数字，遇到运算符就取出栈顶两个计算，放进栈里。
'''

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = list() 
        for token in tokens:
            if token == '+':
                a = num_stack.pop()
                b = num_stack.pop()
                num_stack.append(a + b)
            elif token == '-':
                a = num_stack.pop()
                b = num_stack.pop()
                num_stack.append(b - a)
            elif token == '*':
                a = num_stack.pop()
                b = num_stack.pop()
                num_stack.append(a * b)
            elif token == '/':
                a = num_stack.pop()
                b = num_stack.pop()
                num_stack.append(int(b / a))
            else:
                num_stack.append(int(token))
        return num_stack[0]