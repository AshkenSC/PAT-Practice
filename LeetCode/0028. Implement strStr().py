# 0028. Implement strStr()

'''
1）采用sunday算法
2）注意不匹配时的处理方法：从最末尾看起，找模式串中是否有当前模式串位置的下一个字符
3）考虑一些边界条件：
主串or模式串为空；
主串长度小于模式串；
'''

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # 采用Sunday算法进行字符串匹配
        current_pos = 0
        while not self.is_found(current_pos, haystack, needle):
            try:
                if needle == '' or haystack == '' \
                        or len(haystack) < len(needle)\
                        or current_pos + len(needle) >= len(haystack):
                    return -1
                # 如果模式串所在当前位置的后面一位字符,就将模式串中最末尾开始，第一个出现该字符的位置对准该字符
                if haystack[current_pos + len(needle)] in needle:
                    first_occur_backward = len(needle) - 1 - needle[::-1].index(haystack[current_pos + len(needle)])
                    offset = len(needle) - first_occur_backward
                # 否则直接整个串的开头跳到后面一位字符的后面去
                else:
                    offset = len(needle) + 1
                current_pos += offset
                if current_pos > len(haystack) - len(needle):
                    return -1
            except:
                print('err')
        return current_pos

    def is_found(self, current_pos, haystack: str, needle: str):
        if haystack[current_pos:current_pos+len(needle)] != needle:
            return False
        else:
            return True


# # test
# sol = Solution()
# ans = sol.strStr("aaaaa", "bba")
# print(ans)



