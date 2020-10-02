
/*
0190. Reverse Bits

颠倒给定的 32 位无符号整数的二进制位。

思路：逐个翻转最后一位，参考官方解答。

*/
    
#include <string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int power = 31;
        while (n != 0) {
            // 将最右侧的数位放在结果中
            res += (n & 1) << power;
            // 从右到左检索原始数
            n = n >> 1;
            power--;
        }
        return res;
    }
};