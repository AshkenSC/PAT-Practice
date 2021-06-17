/*
剑指 Offer 56 - II. 数组中数字出现的次数 II

在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

思路：
将所有数字的二进制位相加。
如果能被3整除的位，说明只出现一次的那一位是0；
如果不能整除，就是只出现一次的那一位是1。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> counts(32);
        for (auto num : nums) {
            // 对每一个num，将其与1 做and操作，记录其每一比特位是0还是1
            // 不断右移num，从而记录num的每一位。
            for (int i = 0; i < 32; ++i) {
                counts[i] += num & 1;
                num >>= 1;
            }
        }

        // 对每一位，检查是否能被3整除。检查完了res就左移
        int res = 0, m = 3;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            res |= counts[31 - i] % m;
        }

        return res;
    }
};
