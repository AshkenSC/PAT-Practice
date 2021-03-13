/*
剑指 Offer 53 - II. 0～n-1中缺失的数字

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

思路：关键是想到：将数组分成两个子数组：其中一个a[i] == i, 另一个a[i] != i
接下来就是找a[i] != i的数组的起始位置。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            }
            else if (nums[mid] != mid) {
                right = mid;
            }
        }

        return left;
    }
};
