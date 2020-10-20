'''
0341. Flatten Nested List Iterator

给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

思路：参考https://leetcode-cn.com/problems/flatten-nested-list-iterator/solution/python-zhan-dai-ma-jian-dan-yi-li-jie-by-hsyv5897/
'''

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = nestedList[::-1]
    
    def next(self) -> int:
        return self.stack.pop().getInteger()
    
    def hasNext(self) -> bool:
        # 对栈顶list进行层层去嵌套，直到栈顶存的是int为止
        while len(self.stack) > 0 and self.stack[-1].isInteger is False:
            self.stack += self.stack.pop().getList()[::-1]
        return len(self.stack) > 0