/*
0213. House Robber II

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

思路：
关键在于分类讨论： 可以偷第0个家 和 不可以偷第0个家。

参考：https://leetcode-cn.com/problems/house-robber-ii/solution/213-c-shuang-100-da-jia-jie-she-by-smart_shelly/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
		    return 0;
        if (nums.size() <= 3)
            return *max_element(nums.begin(), nums.end());

        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        dp1[2] = nums[2] + nums[0];
        dp2[1] = nums[1];
        dp2[2] = nums[2];
        dp2[3] = nums[3] + nums[1];

        for (int i = 3; i < nums.size(); i++) {
            if (i == 3) {
                dp1[i] = max(dp1[i - 2], dp1[i - 3]) + nums[i];
            }
            else if (i == nums.size() - 1) {
                dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
            }
            dp1[i] = max(dp1[i - 2], dp1[i - 3]) + nums[i];
            dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
        }

        int result;
        int n = nums.size();
        result = max(dp1[n - 2], dp1[n - 3]);
        result = max(result, dp2[n - 2]);
        result = max(result, dp2[n - 1]);

        return result;
    }
};
