# 1450. Number of Students Doing Homework at a Given Time
from typing import List


class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        output = 0
        for i in range(len(startTime)):
            if startTime[i] <= queryTime <= endTime[i]:
                output += 1
        return output


# # test
# sol = Solution()
# ans = sol.busyStudent(startTime = [1,2,3], endTime = [3,2,7], queryTime = 4)
# print(ans)
