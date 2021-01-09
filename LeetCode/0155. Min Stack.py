'''
0155. Min Stack

思路：和第一版类似，关键是由于题目要求在常数时间找到最小元素，因此就在pop时花时间维护存储最小元素的变量。

'''

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s = list()
        # 最小值，最小值的数有几个
        self.mini_count = [float('inf'), 0]


    def findMin(self):
        new_min = min(self.s)
        new_count = self.s.count(new_min)
        return [new_min, new_count]
        

    def push(self, x: int) -> None:
        self.s.append(x)
        if x < self.mini_count[0]:
            self.mini_count[0] = x
            self.mini_count[1] = 1
        elif x == self.mini_count[0]:
            self.mini_count[1] += 1


    def pop(self) -> None:
        delete = self.s.pop()
        if delete == self.mini_count[0]:
            if self.mini_count[1] == 1:
                if len(self.s) == 0:
                    self.mini_count = [float('inf'), 0]
                else:
                    self.mini_count = self.findMin()
            else:
                self.mini_count[1] -= 1


    def top(self) -> int:
        return self.s[-1]

    def getMin(self) -> int:
        return self.mini_count[0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()