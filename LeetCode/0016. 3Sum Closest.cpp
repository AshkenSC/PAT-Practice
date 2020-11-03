/*
0016. 3Sum Closest

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

思路：按照3Sum的思路一个个找和，一旦有更接近的就更新结果数组res。
设一个i遍历数组，同时设指针L=i+1, R=len-1。
如果当前和比target小，则右移L。如果当前和比target大，则左移R。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return res;
        for (int i = 0; i < nums.size() - 2; i++) {
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int currentSum = nums[i] + nums[L] + nums[R];

                // 如果等于target，直接返回target
                if (currentSum == target)
                    return target;
                // 如果和target差更小了，更新res
                if (abs(currentSum - target) < abs(res - target)) {
                    res = currentSum;
                }
                // 如果当前和比target大，就左移R
                if (currentSum > target) {
                    while (L < R && nums[R] == nums[R - 1])
                        R--;
                    R--;
                }
                // 如果当前和比target小，就右移L
                else {
                    while (L < R && nums[L] == nums[L + 1])
                        L++;
                    L++;
                }
            }
        }

        return res;
    }
};