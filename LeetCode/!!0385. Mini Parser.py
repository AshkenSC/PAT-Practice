'''
0385. Mini Parser

给定一个用字符串表示的整数的嵌套列表，实现一个解析它的语法分析器。
列表中的每个元素只可能是整数或整数嵌套列表。

思路：参考
https://leetcode-cn.com/problems/mini-parser/solution/python3ti-mu-bu-nan-zhi-xu-li-qing-luo-ji-by-salti/

'''

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        # 纯数字情形
        if s[0] != '[':
            return NestedInteger(int(s))
        
        # num当前数字，sign数字符号，is_num前一位是否是数字
        num, sign, is_num = 0, 1, False
        stack = list()

        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
                is_num = True
            elif c == '[':
                stack.append(NestedInteger())
            elif c == '-':
                sign = -1
            elif c == ',' or c == ']':
                # 将当前数字存入列表中
                # 方法是先将栈顶列表取出，将数字放入列表，再放回栈中
                if is_num:
                    cur_list = stack.pop()
                    cur_list.add(NestedInteger(sign * num))
                    stack.append(cur_list)
                num, sign, is_num = 0, 1, False
                # 如果是嵌套情形，要把当前子列表存入母列表中
                if c == ']' and len(stack) > 1:
                    cur_list = stack.pop()
                    stack[-1].add(cur_list)
        
        return stack[0]