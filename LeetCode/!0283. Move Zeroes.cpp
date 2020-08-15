/*
0283. Move Zeroes
给定一个数组，将里面所有的0移动到数组末尾，其他数值保持相对位置不变。

要求：1）不能申请额外的空间；2）操作次数尽可能少。

思路：使用两个指针。i作为快指针，j作为慢指针。i，j同时从数组头开始向后移动，i只要遇到非0，就交换a[i], a[j]的位置（此时i，j本身的位置不变）。
之后，j向后移动1位，i继续向后寻找非0数，直到i达到数组末尾。
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};