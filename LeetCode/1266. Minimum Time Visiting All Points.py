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
                    diagonal_distance = b[0] - a[0]
                    a[0] += diagonal_distance
                    a[1] += diagonal_distance
                    output += abs(diagonal_distance)
                    # 然后水平竖直移动
                    output += abs(a[1] - b[1])
                else:
                    # 先对角线移动
                    diagonal_distance = b[1] - a[1]
                    a[0] += diagonal_distance
                    a[1] += diagonal_distance
                    output += abs(diagonal_distance)
                    # 然后水平竖直移动
                    output += abs(a[0] - b[0])
            i += 1

        return output


# test
sol = Solution()
ans = sol.minTimeToVisitAllPoints([[559,511],[932,618],[-623,-443],[431,91],[838,-127],[773,-917],[-500,-910],[830,-417],[-870,73],[-864,-600],[450,535],[-479,-370],[856,573],[-549,369],[529,-462],[-839,-856],[-515,-447],[652,197],[-83,345],[-69,423],[310,-737],[78,-201],[443,958],[-311,988],[-477,30],[-376,-153],[-272,451],[322,-125],[-114,-214],[495,33],[371,-533],[-393,-224],[-405,-633],[-693,297],[504,210],[-427,-231],[315,27],[991,322],[811,-746],[252,373],[-737,-867],[-137,130],[507,380],[100,-638],[-296,700],[341,671],[-944,982],[937,-440],[40,-929],[-334,60],[-722,-92],[-35,-852],[25,-495],[185,671],[149,-452]])
print(ans)
