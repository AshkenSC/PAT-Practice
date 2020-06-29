class Solution:
    def reverse(self, x: int) -> int:
        sign = 1
        x_str = str(x)
        if x_str[0] == '-':
            sign = -1
            x_str = x_str.replace('-', '')

        # list.reverse() 没有返回值，它会直接对list排序,
        # 所以不要写x_str_list = list(x_str).reverse()
        x_str_list = list(x_str)
        x_str_list.reverse()
        x_str = ''.join(x_str_list)
        # 删除左边多余的0，但要排除恰好为0的情形
        if x_str != '0':
            result_str = x_str.lstrip('0')
        else:
            result_str = x_str
        result = int(result_str) * sign
        return result


# # 测试
# while True:
#     x = int(input())
#     solution = Solution()
#     print(solution.reverse(x))