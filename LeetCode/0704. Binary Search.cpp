/*
0704. Binary Search

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

思路：
有三种小类别：1）找到直接返回；2）返回左边界；3）返回右边界。

参考：
https://www.cnblogs.com/kyoner/p/11080078.html
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
        }
        if (left - 1 >= 0 && nums[left - 1] == target)
            return left - 1;
        else
            return -1;
    }
};
