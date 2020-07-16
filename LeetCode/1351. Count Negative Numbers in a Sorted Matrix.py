# 1351. Count Negative Numbers in a Sorted Matrix
from typing import List


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        negative_count = 0
        for row in grid:
            sub_count = 0
            for i in range(len(row)):
                if row[i] < 0:
                    sub_count += len(row) - i
                    break
            negative_count += sub_count
        return negative_count


sol = Solution()
res = sol.countNegatives([[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]])
print(res)