/*
0709. To Lower Case

将大小写字符串转为纯小写字符串。
*/

class Solution {
public:
    string toLowerCase(string str) {
        string res = "";
        for (char c : str) {
            if (c >= 'A' && c <= 'Z') {
                res += c + 'a' - 'A';
            }
            else {
                res += c;
            }
        }
        return res;
    }
};