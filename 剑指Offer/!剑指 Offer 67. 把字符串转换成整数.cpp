/*
剑指 Offer 67. 把字符串转换成整数

写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

思路：
要考虑的边界条件较多。
必须边加边判断是否溢出，如果最后才判断，最后会大到long long都放不下
*/

class Solution {
public:
    int strToInt(string str) {
        long long res = 0;
        int i = 0;
        bool isNegative = false;

        // 字符串为空
        if (str.size() == 0) {
            return res;
        }
        // 丢弃空字符
        for (; str[i] == ' '; ++i);

        // 第一个非空格字符不是一个有效整数字符
        // 字符串仅包含空白字符时
        // 则你的函数不需要进行转换
        if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
            || i == str.size()) {
            return res;
        }

        // 如果第一个有效字符是符号，处理符号
        if (str[i] == '-') {
            isNegative = true;
            ++i;
        }
        else if (str[i] == '+') {
            isNegative = false;
            ++i;
        }
        
        // 处理数字部分
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + str[i] - '0';
            // 必须边加边判断，如果最后判断，最后会大到long long都放不下
            if (!isNegative && res > INT_MAX) {
                return INT_MAX;
            }
            else if (isNegative && -res < INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }
        // 给绝对值加符号
        res = isNegative ? -res : res;
        return (int)res;
    }
};
