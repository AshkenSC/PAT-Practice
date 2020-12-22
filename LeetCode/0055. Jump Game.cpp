/*
0055. Jump Game

给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

思路：动态规划。
dp数组：每个位置是否可达。
对每个dp[i]，从dp[i - 1]向前逐个判断能否从dp[j]到达dp[i]。
d[j]需要满足：
1）自己本身是可达的；
2）nums[j] >= i - j（类似于加油站，当前站的油必须足够撑过这一程。但和加油站也不同，这道题每到一站，油箱都清空。）

参考https://leetcode-cn.com/problems/jump-game/solution/cdong-tai-gui-hua-hen-jian-dan-de-si-lu-by-warlord/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && nums[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};