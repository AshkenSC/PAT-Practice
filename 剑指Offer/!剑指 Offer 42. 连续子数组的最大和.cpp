/*
剑指 Offer 42. 连续子数组的最大和

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。

思路：
dp[i]，前i个数构成的子数组构成的最大值
dp[0] = 0, dp[1] = a[0]
dp[i] = dp[i - 1] < 0 ? a[i] : dp[i - 1] + a[i - 1]

做过的还不会！！！

*/

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];

        // dp[i]，前i个数构成的子数组构成的最大值
        // dp[0] = 0, dp[1] = a[0]
        // dp[i] = dp[i - 1] < 0 ? a[i] : dp[i - 1] + a[i - 1]
        int former = 0;
        int current;
        int max = a[0];
        for (auto num : a) {
            if (former < 0) {
                current = num;
            }
            else {
                current = former + num;
            }
            if (current > max) {
                max = current;
            }
            former = current;
        }

        return max;
    }
};
