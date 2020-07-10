# 1266. Minimum Time Visiting All Points
'''
1) 如果a和b一开始就在一条直线上（横坐标或者纵坐标相同），则直接水平或竖直移动。
2）如果a和b一开始不在一条直线（横纵坐标都不同），则先对角线移动，直到横/纵坐标相同，然后水平竖直移动。

'''

from typing import List


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        output = 0
        i = 0
        while i < len(points) - 1:
            a = points[i]
            b = points[i + 1]
            # 如果a和b在水平或者竖直线上
            if a[0] == b[0]:
                output += abs(a[1] - b[1])
            elif a[1] == b[1]:
                output += abs(a[0] - b[0])
            # 如果a和b不在水平或者竖直线上
            else:
                if abs(a[0] - b[0]) < abs(a[1] - b[1]):
                    # 先对角线移动
                    output += abs(a[0] - b[0])
                    a[1] += b[0] - a[0]
                    # 然后水平竖直移动
                    output += abs(a[1] - b[1])
                else:
                    # 先对角线移动
                    output += abs(a[1] - b[1])
                    a[0] += b[1] - a[1]
                    # 然后水平竖直移动
                    output += abs(a[0] - b[0])
            i += 1

        return output


# # test
# sol = Solution()
# ans = sol.minTimeToVisitAllPoints([[3,2],[-2,2]])
# print(ans)
