/*
剑指 Offer 59 - I. 滑动窗口的最大值

给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

思路：
用双向队列模拟实现了滑动窗口的过程，同时将这个队列维护成了一个单调队列

参考：
图解参考，更容易理解代码：
https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-i-hua-dong-chuang-kou-de-zui-da-1-6/

代码参考：
https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/hua-dong-chuang-kou-de-zui-da-zhi-by-gnu-diy6/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dp;
        int len = nums.size();
        if (k <= 0 || len <= 0 || len < k) {
            return res;
        }

        for (int i = 0; i < len; ++i) {
            // 队列最小值比当前遍历到的值还要小，弹出
            // 因为他们不可能是窗口中的最大值了
            while (!dp.empty() && nums[i] >= nums[dp.back()]) {
                dp.pop_back();
            }
            dp.push_back(i);

            // 从0到k-2不处理，直接从第一个窗口长度结尾才开始处理
            if (i >= k - 1) {
                res.push_back(nums[dp.front()]);
                // 如果现在的最值等于窗口的第一个值，要弹出
                if (i - k + 1 == dp.front()) {
                    dp.pop_front();
                }
            }
        }

        return res;
    }
};
