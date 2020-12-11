/*
0540. Single Element in a Sorted Array

给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

思路：二分法，关键是利用好：唯一数一定出现在奇数长度数组里。
先找到中点，判断其前后数是否和他相等。
如果都不等，直接找到这个数；
如果前/后相等，则去掉这一对数，将数组分为两个子数组。
唯一数一定出现在奇数长度数组里！！

*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            // int mid = right - (right - left) / 2; 这样写，当left=0，right=1时，mid=1！奇怪
            int mid = left + (right - left) / 2;
            int leftSubEnd, rightSubStart;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                leftSubEnd = mid - 1;
                rightSubStart = mid + 1;
                if ((leftSubEnd - left) % 2 == 1) {
                    right = leftSubEnd;
                }
                else {
                    left = rightSubStart;
                }
            }
            else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                leftSubEnd = mid;
                rightSubStart = mid + 2;
                if ((leftSubEnd - left) % 2 == 1) {
                    right = leftSubEnd;
                }
                else {
                    left = rightSubStart;
                }
            }
            else {
                return nums[mid];
            }
        }

        return nums[left];
    }
};