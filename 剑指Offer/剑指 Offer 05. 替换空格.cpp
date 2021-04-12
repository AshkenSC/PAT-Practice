/*
剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

思路1：逐个字符检查并保存，遇到空格就替换为保存%20。
思路2：原地修改字符串，先根据空格数扩充长度，再在原字符串修改。
*/

// 思路2
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for (char c : s) {
            if (c == ' ') {
                count++;
            }
        }
        s.resize(len + 2 * count);
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            }
            else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }

        return s;
    }
};

// 思路1
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
