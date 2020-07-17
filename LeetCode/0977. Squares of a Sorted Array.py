# 0977. Squares of a Sorted Array


from typing import List


class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        for i in range(len(A)):
            A[i] = A[i] * A[i]
        return sorted(A)


sol = Solution()
res = sol.sortedSquares([-4,-1,0,3,10])
print(res)
