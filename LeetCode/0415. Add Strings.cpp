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
        vector<char> result_bit;

        // 位数少的数，前面补全0
        if (num1.size() < num2.size()) {
            int sizeDiff = num2.size() - num1.size();
            for (int i = 0; i < sizeDiff; i++) {
                num1 = "0" + num1;
            }
        }
        else if (num1.size() > num2.size()) {
            int sizeDiff = num1.size() - num2.size();
            for (int i = 0; i < sizeDiff; i++) {
                num2 = "0" + num2;
            }
        }

        // 逐位计算
        int carry = 0; // 进位位
        for (int i = num1.size() - 1; i >= 0; i--) {
            int currentPos = num1[i] - '0' + num2[i] - '0' + carry;
            if (currentPos < 10) {
                carry = 0;
                currentPos = currentPos + '0';
            }
            else {
                carry = 1;
                currentPos = currentPos - 10 + '0';
            }
            result_bit.insert(result_bit.begin(), currentPos);

            // 如果当前位置是最后一位且需要进位
            if (i == 0 && carry == 1) {
                result_bit.insert(result_bit.begin(), '1');
            }
        }


        // 结果拼接字符串
        string result_str = "";
        for (int i = 0; i < result_bit.size(); i++) {
            result_str += result_bit[i];
        }

        return result_str;
    }
};