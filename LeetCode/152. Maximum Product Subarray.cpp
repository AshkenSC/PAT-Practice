/*
0152. Maximum Product Subarray

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），
并返回该子数组所对应的乘积。

思路：
参考https://leetcode-cn.com/problems/maximum-product-subarray/solution/xu-yao-wei-hu-yi-ge-zui-xiao-zhi-by-javaniuniu/
贪心算法，记录每次遍历的最大和最小值。
当遇到负数时，最大和最小值颠倒。
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int iMax = 1, iMin = 1;
        int res = nums[0];
        for (int num : nums) {
            // 这一句是核心，一旦遇到负数，则大小调换，攻守之势易也
            if (num < 0) {
                swap(iMax, iMin);
            }
            iMax = max(num, iMax * num);
            iMin = min(num, iMin * num);
            res = max(res, iMax);
        }
        return res;
    }
};