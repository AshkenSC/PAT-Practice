# 1252. Cells with Odd Values in a Matrix
'''
遍历indices每个子列表，每次对应的行和列增加1。

用列表解析创建n行m列的二维列表
 matrix = [[0 for col in range(m)] for row in range(n)]
'''

from typing import List


class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        # 用列表解析创建二维列表
        matrix = [[0 for col in range(m)] for row in range(n)]
        # 遍历indices中每个子列表，对应行和列增加1
        for index in indices:
            row = index[0]
            col = index[1]
            # 对应行增加1
            for i in range(m):
                matrix[row][i] += 1
            # 对应列增加1
            for i in range(n):
                matrix[i][col] += 1
        # 检查奇数元素数
        odd = 0
        for row in matrix:
            for element in row:
                if element % 2 == 1:
                    odd += 1

        return odd


# # test
# sol = Solution()
# ans = sol.oddCells(2, 3, [[0,1],[1,1]])
# print(ans)
