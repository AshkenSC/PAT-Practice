/*
0238. Product of Array Except Self

思路：参考官方解法1.
先从左向右遍历，获取每个元素左边数值的乘积；
再从右向左遍历，获取每个元素右边数值的乘积；
再将两个乘积相乘，得到每个元素总乘积。
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> L(length, 0), R(length, 0);

        L[0] = 1;
        for (int i = 1; i < length; i++) {
            L[i] = L[i - 1] * nums[i - 1];
        }

        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = R[i + 1] * nums[i + 1];
        }

        vector<int> result(length);
        for(int i = 0; i < length; i++) {
            result[i] = L[i] * R[i];
        }

        return result;
    }
};