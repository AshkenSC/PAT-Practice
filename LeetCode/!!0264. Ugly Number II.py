'''
0264. Ugly Number II

编写一个程序，找出第 n 个丑数。
丑数就是质因数只包含 2, 3, 5 的正整数。

思路：动态规划，参考官方解答。
注意：由于i2 i3 i5所指向的可能重复，所以必须用if不能用elif！！！
例如 6 = 3 * 2 = 2 * 3
'''

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_set = [1]
        i2 = 0
        i3 = 0
        i5 = 0
        while len(ugly_set) < 1690:
            new_ugly = min(ugly_set[i2] * 2, ugly_set[i3] * 3, ugly_set[i5] * 5)
            ugly_set.append(new_ugly)
            
            # 由于i2 i3 i5所指向的可能重复，所以必须用if不能用elif！！！
            # 例如 6 = 3 * 2 = 2 * 3
            if new_ugly == ugly_set[i2] * 2:
                i2 += 1
            if new_ugly == ugly_set[i3] * 3:
                i3 += 1
            if new_ugly == ugly_set[i5] * 5:
                i5 += 1

        return ugly_set[n - 1]
     