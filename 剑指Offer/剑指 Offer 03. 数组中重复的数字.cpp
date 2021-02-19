/*
剑指 Offer 03. 数组中重复的数字

思路：原地哈希。
参考答案：
https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/yuan-di-zhi-huan-shi-jian-kong-jian-100-by-derrick/

*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }

        return -1;
    }
};
