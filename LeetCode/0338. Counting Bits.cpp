/*

0338. Counting Bits

给定一个非负整数，对每个在 0 ≤ i ≤ num范围内的整数i，计算它们二进制形式下含有1的个数，以数组形式返回。

思路1：用STL的bitset，其中的count函数进行1个数的计数。
*/

class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> result;
        for (int i = 0; i <= num; i++)
        {
            std::bitset<32> bits(i);
            result.push_back(bits.count());
        }
        return result;
    }
};