/*
0081. Search in Rotated Sorted Array II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
本题中的 nums  可能包含重复元素。

思路：参考https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/

关键：
10111 和 11101 这种。此种情况下 nums[start] == nums[mid]，分不清到底是前面有序还是后面有序，
此时 start++ 即可。相当于去掉一个重复的干扰项。
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return false;
        if (len < 2)
            return target == nums[0] ? true : false;

        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            
            // 本题与33题的关键区别！处理分不清前面有序还是后面有序的情形
            // 例如10111 和 11101
            if (nums[mid] == nums[left]) {
                ++left;
                continue;
            }

            if (nums[mid] > nums[left]) {
                // nums[mid] 在前面就考察过了，所以不取等号。
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                // nums[mid] 在前面就考察过了，所以不取等号。
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
