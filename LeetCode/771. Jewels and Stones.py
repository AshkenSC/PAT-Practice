# 771. Jewels and Stones


class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        jewel_num = 0
        for char in S:
            if char in J:
                jewel_num += 1
        return jewel_num


# sol = Solution()
# res = sol.numJewelsInStones(J = "z", S = "ZZ")
# print(res)