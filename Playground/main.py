# 198
'''
1) 起点
dp[i][j] = dp[i][j]

2) 只能从左边来
dp[i][j] = dp[i][j - 1]

3) 只能从上边来
dp[i][j] = dp[i - 1][j]

4) 可以从上和左来
dp[i][j] = min(dp[i][j - 1], dp[i - 1][j])


'''

from typing import List

class Solution:
    def is_palindrome(self, s):
        start = 0
        end = len(s) - 1
        while start < end:
            if s[start] != s[end]:
                return False
            else:
                start += 1
                end -= 1
        return True

    def backtrack(self, current, s, start, end):
        if start == end:
            if start == len(s) and 
            return
        else:
            for i in range(end, len(s) + 1):
                for j in range(i, len(s) + 1):
                    # 将当前子串添加到结果列表
                    if self.is_palindrome(s[i:j]):
                        current.append(s[i:j])
                        self.backtrack(current, s, i, j)
                        current.pop()

    def partition(self, s: str) -> List[List[str]]:
        res = []
        for i in range(1, len(s) + 1):
            current = []
            if self.is_palindrome(s[0:i]):
                current += s[0:i]
                self.backtrack(current, s, 0, i)
                if len(current) > 1:
                    res += current
        return res


sol = Solution()
res = sol.partition('aab')
print(res)