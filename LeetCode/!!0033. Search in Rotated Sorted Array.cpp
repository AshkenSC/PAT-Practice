/*
0033. Search in Rotated Sorted Array

思路1：先找到断点的位置。找到以后，在其中一个子数组中进行寻找。

思路2：参考官方解答。解答思路中核心一句话：
“我们能够根据有序的那部分判断出 target 在不在这个部分”
虽然整体不是有序的，但是我们可以找到有序的那一部分，然后根据这一小部分来逐步缩小范围。
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
                // target == nums[mid] 在上面已经单独考察过了，所以不取等号。
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                // target == nums[mid] 在上面已经单独考察过了，所以不取等号。
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
最后卡在了，如果数组中找不到这个元素的情况。
比如[1, 3]，找2，就会报错。

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
                        return mid;
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
