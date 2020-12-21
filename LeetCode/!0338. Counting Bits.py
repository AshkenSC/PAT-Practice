'''
0338. Counting Bits

给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

思路：
将除了0和1以外，其他的数字中1的数目都可以看作之前已有的某个数字前面加上一个1。
这个之前的数字pre就是当前数字i - 不大于i的最大2次幂。

'''

from typing import List
import math

class Solution:
    def countBits(self, num: int) -> List[int]:
        if num == 0:
            return [0]
        
        res = [0, 1]
        for i in range(2, num + 1):
            pre = i - 2 ** int(math.log(i) / math.log(2))
            res.append(1 + res[pre])
        return res

sol = Solution()
res = sol.countBits(4)
print(res)