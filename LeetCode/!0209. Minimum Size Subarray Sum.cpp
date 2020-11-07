/*
0209. Minimum Size Subarray Sum

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，
并返回其长度。如果不存在符合条件的子数组，返回 0。

思路：
设两指针start和end，初始化为start = 0， end = 0.设最终输出结果（最小长度）为res，设start到end的和sum。
执行下列循环，直到end遇到nums结尾：
    将当前end指向的值：nums[end]进入sum。
    检查sum是否大于等于s了
        如果小于s则继续移动end
        如果已经大于等于s则执行循环，直到sum不再大于等于s：
            检查当前start到end子数组的长度是否更小。如果更小，则更新res。
            将start向前移动一位，同时更新sum。
    end向后移动一位
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;

        int res = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;

        while (end < nums.size()) {
            sum += nums[end];
            while (sum >= s) {
                res = min(res, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return res == INT_MAX ? 0 : res;
    }
};