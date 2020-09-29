/*
0171. Excel Sheet Column Number

给定一个Excel表格中的列名称，返回其相应的列序号。

思路：把这当成一个27进制数即可。
*/

class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = res * 26;
            res = res + s[i] - 'A' + 1;
        }
        return res;
    }
};