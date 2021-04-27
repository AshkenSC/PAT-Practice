/*
剑指 Offer 53 - I. 在排序数组中查找数字 I

统计一个数字在排序数组中出现的次数。

二分查找经典题！参考：
https://www.cnblogs.com/kyoner/p/11080078.html

一开始，写的是right = nums.size() - 1, left < right，
这种写法会导致测试例子[1]中，left会缩到-1。这样不对。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, mid;
        int targetStart, targetEnd;

        left = 0; right = nums.size();
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
        }
        targetStart = left;

        // 别忘记复位left right
        left = 0; right = nums.size();
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
        targetEnd = left - 1;

        return targetEnd - targetStart + 1;
    }
};

