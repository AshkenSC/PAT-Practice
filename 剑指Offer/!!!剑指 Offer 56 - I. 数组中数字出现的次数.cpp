/*
剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

思路：
参考官方解答，非常巧妙。核心是理解：为什么这样分成两组，可以正好把相同数分在一组，两个不同数分在两组。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 首先，将nums中的所有数进行亦或。
        // 最终得到的ret，出现两次的数亦或得全0，两个单独的数互不相同的比特位在ret中为1
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }

        // 找到ret中为1的最低位，也就是两个单独的数最低的不同比特位
        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }

        // 利用上一步找到的最低不同比特位div，进行分组
        // 和div做亦或操作，等于1，放到a组，等于0，放到b组
        // 出现两次的数由于在该位相同，会被分到同一组，从而消去
        // 出现一次的两个数由于在该位不同，所以必定会分到不同组
        int a = 0, b = 0;
        for (int n : nums) {
            if (div & n)
                a ^= n;
            else
                b ^= n;
        }

        return vector<int>{a, b};
    }
};

