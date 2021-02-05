/*
0415. Add Strings

给定两个非负整数num1, num2，用字符串表示，返回num1和num2之和。

思路：
1）先把位数少的前面补全0
2）模拟人算加法，从低位起逐位相加
当前位=数位1+数位2+进位，
如果当前位=0-9，则进位=0；
如果当前为=10-18，则当前位=当前位-10，进位=1
3）最高位的处理
如果当前位是最高位，且计算结果进位=1，则前面还要补一位
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        // 将位数少的前面补0
        if (num1.size() < num2.size()) {
            addZero(num1, num2.size() - num1.size());
        }
        else {
            addZero(num2, num1.size() - num2.size());
        }

        // 逐位计算
        vector<char> res;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int curDigit = num1[i] - '0' + num2[i] - '0' + carry;
            if (curDigit >= 10) {
                curDigit -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            res.insert(res.begin(), curDigit + '0');
        }

        // 拼接结果字符串
        // 注意最高位是否满10进1
        string resStr;
        if (carry == 1) {
            resStr = "1";
        }
        for (char c : res) {
            resStr += c;
        }
        return resStr;
    }

    void addZero(string &num, int diff) {
        for (int i = 0; i < diff; ++i) {
            num = '0' + num;
        }
    }
};
