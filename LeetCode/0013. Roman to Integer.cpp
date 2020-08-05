/*
0013. Roman to Integer

给定一个罗马数字，将其转为整数。


思路1：
分为三部分计算：C放在D，M左右的部分；X放在L,C左右的部分，I放在V,X左右的部分。
1）C放在D，M左右的部分：如果在D,M出现前，C出现了，则C是-100，否则C是100.
2）X放在L, C左右的部分：如果在L,C出现前，X出现了，则X是-10，否则是10.
3）I放在V, X左右的部分：如果在V,X出现前，I出现了，则I是-1，否则是1.

思路2：
不需要分多种情况讨论，可以总结为：从左到右读取字符串，如果当前位置字符对应的值小于等于前一个位置字符对应的值，最终值就加上上一个位置字符对应值，否则就减去上一个位置字符对应值。
*/


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> valueMap{ {'I',1}, {'V',5}, {'X',10}, {'L',50},
                                    {'C',100}, {'D',500}, {'M',1000} };
        int result = 0;

        for (int i = 1; i < s.size(); i++) {
            if (valueMap[s[i]] <= valueMap[s[i - 1]]) {
                result += valueMap[s[i - 1]];
            }
            else {
                result -= valueMap[s[i - 1]];
            }
        }
        result += valueMap[s[s.size()-1]];

        return result;
    }
};