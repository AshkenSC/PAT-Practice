'''
0093. Restore IP Addresses

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

思路：总体是回溯法。
进行三次分割，每次分割出1/2/3位数。如果当前分割出的数合法，则继续进行下一次分割，否则退出。
如果最后一次分割剩下的部分不合法，则退出，否则将当前结果存进res。

分割过程中一些规则：
1）如果开头是0，则单独分割为一个数；
2）数位不超过三位；
3）如果数位是三位，则值不大于255；

其他细节问题参见注释。
自己写出来了！耶！

'''

from typing import List

class Solution:
    def __init__(self):
        self.res = []
        self.current_ip = []

    # 检查当前分割的这个数是否合法
    def is_valid_num(self, s):
        if len(s) < 1:
            return False
        # 如果开头是0，那这个数只能是纯0
        if s[0] == '0':
            if len(s) == 1:
                return True
            else:
                return False
        else:
            if len(s) <= 3 and int(s) <= 255:
                return True
            else:
                return False

    def backtrack(self, s, split_time):
        # 已经进行了三次分割
        if split_time == 3:
            # 如果最后剩下的数字部分是合法的，则保存结果并返回
            if self.is_valid_num(s):
                self.current_ip.append(s)
                self.res.append('.'.join(self.current_ip))
                self.current_ip.pop() # 注意要这里要删除current ip第四部分，否则会残留到下一轮
            # 否则直接返回
            return
        # 分割未结束，继续分割
        else:
            # 一次分割出的数字长度从1-3
            for i in range(1, 4):
                cur_num = s[0:i]    # 新分割出的数字
                # 新分割出的数字不合法，则退出
                if not self.is_valid_num(cur_num):
                    continue
                # 若合法，则递归进行下一层分割
                else:
                    original_s = s[:]                   # 将原始s存档，便于回溯
                    s = s[i:]                           # 将s修改为剩下还没被分割的部分
                    self.current_ip.append(cur_num)
                    # 递归进行下一层分割
                    self.backtrack(s, split_time + 1)
                    # 回溯
                    s = original_s
                    self.current_ip.pop()


    def restoreIpAddresses(self, s: str) -> List[str]:
        self.backtrack(s, 0)
        return self.res

sol = Solution()
res = sol.restoreIpAddresses("25525511135")
print(res)
