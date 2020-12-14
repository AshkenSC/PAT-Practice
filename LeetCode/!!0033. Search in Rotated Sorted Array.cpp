/*
0033. Search in Rotated Sorted Array

思路：先找到断点的位置。找到以后，在其中一个子数组中进行寻找。

*/

#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len < 2) {
            nums[0] == target ? 0 : -1;
        }

        int left = 0, right = len - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[len - 1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            
        }

        return -1;
    }
};

/*
第一遍写的垃圾，留着，好好反思！

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 2) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
        }

        // 如果根本就没旋转
        if (mid == 0) {
            left = 0, right = nums.size() - 1;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (nums[mid] < target) {
                    left = mid + 1;
                }
                else if (nums[mid] > target) {
                    right = mid;
                }
                else if (nums[mid] == target) {
                    left = mid + 1;
                }
            }

            if (left - 1 < 0 || left - 1 >= nums.size())
                return -1;
            else
                return left - 1;
        }
        else {
            int sub1L = 0, sub1R = mid - 1, sub2L = mid, sub2R = nums.size() - 1;
            if (target >= nums[sub1L] && target <= nums[sub1R]) {
                left = sub1L;
                right = sub1R + 1;
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

                    if (left < sub1L || left > sub1R) {
                        return -1;
                    }
                    else {
                        return left;
                    }
                }
            }
            else if (target >= nums[sub2L] && target <= nums[sub2R]) {
                left = sub2L;
                right = sub2R;
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

                    if (left < sub2L || left > sub2R) {
                        return -1;
                    }
                    else {
                        return left;
                    }
                }
            }
        }


        return -1;
    }
};
*/
