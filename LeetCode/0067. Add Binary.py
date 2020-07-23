# 0067. Add Binary

'''
1）先把位数少的前面补全0
2）模拟人计算加法，从低位起逐个位相加
当前位=数位1+数位2+进位
如果当前位=0或者1，则：当前位=0或1，进位=0
如果当前位=2或3，则：当前位=0或1，进位=1
3）最高位的处理
如果当前位置是最高位，且进位=1，前面还要补一位
'''


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result_bit_list = list()

        # 位数少数，前面补全0
        if len(a) < len(b):
            a = '0' * (len(b) - len(a)) + a
        elif len(a) > len(b):
            b = '0' * (len(a) - len(b)) + b

        # 逐位计算
        carry = 0   # 进位
        for i in range(len(a) - 1, -1, -1):
            current_pos = int(a[i]) + int(b[i]) + carry
            if current_pos <= 1:
                carry = 0
                current_pos = str(current_pos)
            else:
                carry = 1
                current_pos = str(current_pos - 2)
            result_bit_list.insert(0, current_pos)

            # 如果当前是最后一位，且需要进位
            if i == 0 and carry == 1:
                result_bit_list.insert(0, '1')

        # 将结果拼接为一个字符串
        result_str = ''.join(result_bit_list)
        return result_str


sol = Solution()
res = sol.addBinary(a = "1010", b = "1011")
print(res)
