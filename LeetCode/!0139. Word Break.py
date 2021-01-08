'''
0139. Word Break

其实不难，但自己就是没想到！

思路：动态规划
dp[i] 表示前i位是否可以用词典里的词表示。
如果dp[i]为true，而且dp[i:j]在字典里，那么dp[j]也为true

参考：https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-ji-yi-hua-hui-su-zhu-xing-jie-shi/

'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(n):
            for j in range(i + 1, n + 1):
                if dp[i] and s[i:j] in wordDict:
                    dp[j] = True
        
        return dp[-1]
