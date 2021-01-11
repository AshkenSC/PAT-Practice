'''
0378. Kth Smallest Element in a Sorted Matrix

使用堆排序思想重写。

但是，对于heapq如何对元组进行堆排序的原理，还不太清楚。

'''

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        pq = [(matrix[i][0], i, 0) for i in range(n)]
        heapq.heapify(pq)

        for i in range(k - 1):
            num, x, y = heapq.heappop(pq)
            if y != n - 1:
                heapq.heappush(pq, (matrix[x][y + 1], x, y + 1))

        return heapq.heappop(pq)[0]
        