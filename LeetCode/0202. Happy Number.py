'''
0202. Happy Number

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为1，那么这个数就是快乐数。
'''

class Solution:
    def isHappy(self, n: int) -> bool:
        appeared = list()
        current_num = n
        while current_num not in appeared:
            appeared.append(current_num)
            new_num = 0
            for digit in str(current_num):
                new_num += int(digit) ** 2
            if new_num == 1:
                return True
            current_num = new_num
        return False
            
sol = Solution()
print(sol.isHappy(19))