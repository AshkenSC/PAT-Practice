/*
0034. Find First and Last Position of Element in Sorted Array

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。

思路：
进行两次二分查找，分别找到左边界和右边界。
找寻左右边界的方法参考https://www.cnblogs.com/kyoner/p/11080078.html
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findLeft(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        // target比所有值都要大
        if (left >= nums.size())
            return -1;
        if (nums[left] == target)
            return left;
        else
            return -1;
    }

    int findRight(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return -1;

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        // target比所有值都小
        if (left == 0)
            return -1;
        if (nums[left - 1] == target)
            return left - 1;
        else
            return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }
};

// 二刷，不知道怎么测试用例过不去：[2, 2], 3
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res({-1, -1});
        if (nums.size() == 0)
            return res;

        int left = 0, right = nums.size();
        int mid;
        // 找左边界
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (nums[right] == target) {
            res[0] = right;
        }

        // 找右边界
        left = 0; right = nums.size();
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (left - 1 >= 0 && nums[left - 1] == target) {
            res[1] = left - 1;
        }
        
        return res;
    }
};
