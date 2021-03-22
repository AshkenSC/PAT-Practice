/*
剑指 Offer 58 - I. 翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

思路：
想到原地翻转比较难。

参考
https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/solution/151-fan-zhuan-zi-fu-chuan-li-de-dan-ci-y-hn6y/
*/

class Solution {
public:
    string reverseWords(string s) {
        if (s == "") {
            return "";
        }

        bool rIsBlank = true;       // 标记原字符串中当前字符右边是否为空格
        int insertIndex = 0;        // 字符串插入位置
        int count = 0;              // 反转后新字符串长度
        int end = s.size() - 1;     // 指向当前字符串s的最后一个字符位置

        for (int i = s.size(); i > 0; --i) {
            // 遇到多余空格，删除
            if (rIsBlank && s[end] == ' ') {
                s.erase(end--, 1);
                rIsBlank = true;
            }
            // 遇到单词左边空格
            else if (!rIsBlank && s[end] == ' ') {
                insertIndex = count;
                // 一边在头部插入，一边在尾部删除
                // 同时确保end一直指向整个字符串的尾部
                s.insert(insertIndex++, 1, s[end++]);
                s.erase(end--, 1);
                rIsBlank = true;
                ++count;
            }
            // 遇到单词
            else {
                s.insert(insertIndex, 1, s[end++]);
                s.erase(end--, 1);
                rIsBlank = false;
                ++count;
            }
        }

        // 开头判断一次，在这里又要判断一次
        // 这是为了处理形如“   ”等多个空格字符串的情况
        if (s == "") {
            return s;
        }

        if (s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1, 1);
        }

        return s;
    }
};
