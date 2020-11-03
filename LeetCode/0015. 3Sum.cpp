/*
0015. 3Sum

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

思路:
https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
1. 对数组进行排序。判别特殊情况：长度小于3，返回[]
2. 遍历数组元素i，同时设立两个指针。一个指针L从i+1开始，另一个指针R从n-1开始。这样就指向了三个数。
当L<R时执行循环：
3. 如果nums[i]>0，那么后面之和一定大于0，跳过不遍历。
4. 如果有nums[i] + nums[L] + nums[R] == 0，则判断左边和右边是否和下一位重复，去除重复解。
同时将L和R移动到下一个位置，寻找新解。
5. 如果和大于0，说明nums[R]太大，R左移动。如果和小于0，说明nums[R]太小，L右移动

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    res.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                        L++;
                    while (L < R && nums[R] == nums[R - 1])
                        R--;
                    L++;
                    R--;
                }
                else if (sum > 0) {
                    R--;
                }
                else {
                    L++;
                }
            }
        }
        return res;
    }
};
