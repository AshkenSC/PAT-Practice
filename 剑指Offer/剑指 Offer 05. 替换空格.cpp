/*
剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

思路：逐个字符检查并保存，遇到空格就替换为保存%20。
*/

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (const char& c : s) {
            if (c == ' ') {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else {
                res.push_back(c);
            }
        }

        return res;
    }
};
