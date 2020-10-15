/*
0520. Detect Capital

给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        string allCapital = "";
        string allLower = "";
        string firstCapital = "";
        for (int i = 0; i < word.size(); i++) {
            if (i == 0) {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    allCapital += word[i] + 'A' - 'a';
                    allLower += word[i];
                    firstCapital += word[i] + 'A' - 'a';
                }
                else {
                    allCapital += word[i];
                    allLower += word[i] + 'a' - 'A';
                    firstCapital += word[i];
                }
            }
            else {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    allCapital += word[i] + 'A' - 'a';
                    allLower += word[i];
                    firstCapital += word[i];
                }
                else {
                    allCapital += word[i];
                    allLower += word[i] + 'a' - 'A';
                    firstCapital += word[i] + 'a' - 'A';
                }
            }
        }

        if (word == allLower || word == allCapital || word == firstCapital) {
            return true;
        }
        else {
            return false;
        }
    }
};