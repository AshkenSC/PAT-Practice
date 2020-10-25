'''
0079. Word Search

给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

思路：参考
https://leetcode-cn.com/problems/word-search/solution/zai-er-wei-ping-mian-shang-shi-yong-hui-su-fa-pyth/

我好笨啊，背都背了好久！哎。。

'''
from typing import List


class Solution:
    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    def exist(self, board: List[List[str]], word: str) -> bool:
        # 初始化地图的长m，宽n，已走过的位置标记数组marked
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        marked = [[False for _ in range(n)] for _ in range(m)]

        # 所有点都需要作为起点走一遍
        for i in range(m):
            for j in range(n):
                if self.__search_word(board, word, 0, i, j, m, n, marked):
                    return True
        # 如果在上述遍历中都没有找到，则返回false
        return False

    def __search_word(self, board, word, index, start_x, start_y, m, n, marked):
        # 首先判断中止条件
        if index == len(word) - 1:
            return board[start_x][start_y] == word[index]

        # 如果当前位置匹配，则进行递归搜索
        if word[index] == board[start_x][start_y]:
            # 首先将当前位置标为marked
            marked[start_x][start_y] = True
            # 检查所有方向是否可行
            for direction in self.directions:
                # 计算下一步的坐标
                new_x = start_x + direction[0]
                new_y = start_y + direction[1]
                # 递归判断路径是否可行
                # 需要注意：坐标不能越界；不能走已经走过的位置
                if 0 <= new_x < m and 0 <= new_y < n and \
                        not marked[new_x][new_y] and \
                        self.__search_word(board, word, index + 1, new_x, new_y, m, n, marked):
                    return True
            # 如果在上面循环中没有找到可行路线
            marked[start_x][start_y] = False
        return False


sol = Solution()

board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCB"
print(sol.exist(board, word))
