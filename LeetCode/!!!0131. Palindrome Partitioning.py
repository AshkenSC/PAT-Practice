'''
0131. Palindrome Partitioning

耻辱啊！！！做了一整天！！！

思路：参考吱吱

'''

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if len(s) == 0:
            return [[]]
        
        result = []
        for i in range(1, len(s) + 1):
            left = s[:i]
            right = s[i:]
            if left == left[::-1]:
                right = self.partition(right)
                for j in range(len(right)):
                    result.append([left] + right[j])
        
        return result