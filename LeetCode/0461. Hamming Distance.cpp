/*
0461. Hamming Distance

计算两个数字的汉明距离，也就是转为二进制以后，对应位不相同的个数。

思路：
将两个数转为二进制，位少的补齐。然后对比对应位置字符。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {

        int distance = 0;

        // 转为二进制字符串
        // 考虑x, y = 0的情况
        string x_bin = intToBinaryString(x);
        string y_bin = intToBinaryString(y);

        // 补齐长度
        if (x_bin.size() < y_bin.size()) {
            while (x_bin.size() < y_bin.size())
                x_bin = '0' + x_bin;
        }
        else if (x_bin.size() > y_bin.size()) {
            while (y_bin.size() < x_bin.size())
                y_bin = '0' + y_bin;
        }

        // 比较
        for (int i = 0; i < x_bin.size(); i++) {
            if (x_bin[i] != y_bin[i])
                distance++;
        }

        return distance;
    }

    string intToBinaryString(int x) {
        string result = "";
        if (x == 0)
            return "0";
        while (x > 0) {
            result += '0' + x % 2;
            x = x / 2;
        }
        // 反转字符串
        reverse(result.begin(), result.end());
        return result;
    }
};