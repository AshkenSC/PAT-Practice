/*
0136. Single Number

给定一个数组，里面的数字都是出现两次的，除了有一个数字只出现一次。找到那个数。

思路1：用字典存储所有出现的数和他们出现的次数。找到出现次数为1的那个数即可。

思路2：使用XOR!!两两相同数，XOR结果为0。而XOR又满足交换律。那么对于任意数组a,b,a,b,c，XOR的结果为：
a ^ a ^ b ^ b ^ c = 0 ^ 0 ^ c = c
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> appearance;
        for (int i = 0; i < nums.size(); i++) {
            if (appearance.count(nums[i]) == 0)
                appearance[nums[i]] = 1;
            else
                appearance[nums[i]] += 1;
        }
        for (auto entry : appearance) {
            if (entry.second == 1)
                return entry.first;
        }
        return 0;
    }
};