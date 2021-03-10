/*
剑指 Offer 50. 第一个只出现一次的字符

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

思路：用长度26的数组做哈希表，遍历记录出现次数。
再遍历一次字符串，遇到第一个occur次数为1的返回。
*/

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> occur(26);
        for (char c : s) {
            occur[c - 'a']++;
        }
        for (char c : s) {
            if (occur[c - 'a'] == 1) 
                return c;
        }
        return ' ';
    }
};
