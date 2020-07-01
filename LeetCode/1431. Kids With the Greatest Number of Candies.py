# 1431. Kids With the Greatest Number of Candies

from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        output = list()
        for i in range(len(candies)):
            temp = candies[:]   # 这里增加[:]，使用值传递，否则是地址传递，会导致结果错误
            temp[i] += extraCandies
            if temp[i] == max(temp):
                output.append("true")
            else:
                output.append("false")

        return output


# test
candies = [2,3,5,1,3]
extra_candies = 3
solution = Solution()
print(solution.kidsWithCandies(candies, extra_candies))