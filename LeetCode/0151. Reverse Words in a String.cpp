/*
0151. Reverse Words in a String

给定一个字符串，逐个翻转字符串中的每个单词。

*/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        
        string temp;
        for (char c : s) {
            // 如果是空格字符，且缓存字符串非空，将缓存单词存入栈
            if (c == ' ') {
                if (temp.size() > 0) {
                    words.push(temp);
                    temp = "";
                }
                else
                    continue;
            }
            // 非空字符，则存入缓存单词字符串后面
            else {
                temp.push_back(c);
            }
        }
        // 将最后一个单词入栈
        if (temp.size() > 0)
            words.push(temp);

        string res;
        while (words.size() > 1) {
            res += words.top() + " ";
            words.pop();
        }
        res += words.top();
        words.pop();

        return res;
    }
};
