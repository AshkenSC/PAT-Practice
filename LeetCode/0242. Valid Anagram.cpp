/*
0242. Valid Anagram

给定两个字符串，判断是否是同字母组成但排序不同的两个字符串，即字母异位词（anagram）。

思路：
将字符串排序，然后对比二者是否相等。如果相等，则为anagram。
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == "" || t == "") {
            if (s == t)
                return true;
            else
                return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};
