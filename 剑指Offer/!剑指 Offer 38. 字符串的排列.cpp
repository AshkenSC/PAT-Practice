/*
剑指 Offer 38. 字符串的排列

输入一个字符串，打印出该字符串中字符的所有排列。

回溯法基本题，又忘记了，真不应该。
*/

class Solution {
public:
    vector<string> res;

    void backtrack(string &s, int start) {
        if (start == s.size() - 1) {
            res.push_back(s);
            return;
        }

        // 用于记录出现过的字母，避免输出重复排列
        unordered_set<char> appeared;

        for (int i = start; i < s.size(); ++i) {
            if (appeared.count(s[i]) == 1) {
                continue;
            }
            else {
                appeared.emplace(s[i]);
            }
            
            swap(s[i], s[start]);
            backtrack(s, start + 1);
            swap(s[i], s[start]);
        }
    }

    vector<string> permutation(string s) {
        backtrack(s, 0);
        return res;
    }
};
