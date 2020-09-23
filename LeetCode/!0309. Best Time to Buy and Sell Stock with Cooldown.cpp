/*
0309. Best Time to Buy and Sell Stock with Cooldown

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

思路：动态规划

同时要理解：买入为负收益，卖出为正收益

初始状态：
dp[0][0] = -prices[0] （第一天就持有，直接买入）
dp[0][1] = 0
dp[0][2] = 0

dp[i][0] 第i天手中持有股票时的最大收益
dp[i][1] 第i天处于冷冻期的最大收益
dp[i][2] 第i天手中没有股票，也不处于冷冻期的最大收益

如果第i天手中持有股票，说明今天刚刚买入了，或者i-1天手中也持有股票
如果第i天处于冷冻期，只可能是昨天刚刚卖出，因此收益为i-1天的收益加今天卖出的收益
如果第i天手中没有股票，说明i-1天可能没有股票，或者i-1天处于冷冻期
*/

#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {      
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(3));
        // dp[i][0] 第i天手中持有股票时的最大收益
        // dp[i][1] 第i天处于冷冻期的最大收益
        // dp[i][2] 第i天手中没有股票，也不处于冷冻期的最大收益
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 如果第i天手中持有股票，说明今天刚刚买入了，或者i-1天手中也持有股票
            dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0]);
            // 如果第i天处于冷冻期，只可能是昨天刚刚卖出，因此收益为i-1天的收益加今天卖出的收益
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 如果第i天手中没有股票，说明i-1天可能没有股票，或者i-1天处于冷冻期
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        // 最后一天手上还持有股票没有意义，因此最终是比较冷冻期或者不持股谁更大
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};