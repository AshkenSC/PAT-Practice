'''
0205. Isomorphic Strings

给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

思路：遍历两个字符串，用字典记录出现的字母及出现过的所有位置。
例如egg，记录为{e:[0], g:[1, 2]}
输出两个字典的values构成的集合，只要相等即可。

但集合中不能存list这种unhashable类型，必须转为tuple才行。
'''

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_occur = dict()
        t_occur = dict()

        # 遍历s和t，得到出现位置集合
        for i in range(len(s)):
            if s[i] in s_occur.keys():
                s_occur[s[i]].append(i)
            else:
                s_occur[s[i]] = [i]
        for i in range(len(t)):
            if t[i] in t_occur.keys():
                t_occur[t[i]].append(i)
            else:
                t_occur[t[i]] = [i]
        
        # 输出两个结点的values构成的集合
        # 要先把values中的list转为tuple
        s_set = set()
        t_set = set()
        for occur in s_occur.values():
            s_set.add(tuple(occur))
        for occur in t_occur.values():
            t_set.add(tuple(occur))

        if s_set == t_set:
            return True
        else:
            return False 