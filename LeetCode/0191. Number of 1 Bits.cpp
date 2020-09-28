/*
0191. Number of 1 Bits

编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数

思路：考察逐个位，用只有一位为1的掩码逐个考察。
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        long mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((mask & n) != 0)
                cnt++;
            mask = mask << 1;
        }
        return cnt;
    }
};