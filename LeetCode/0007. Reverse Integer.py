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
        result_str = ''.join(x_str_list).lstrip('0')
        result = int(result_str) * sign
        return result

#
# while True:
#     x = int(input())
#     solution = Solution()
#     print(solution.reverse(x))