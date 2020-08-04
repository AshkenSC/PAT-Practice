/*
0122. Best Time to Buy and Sell Stock II

给定一个某股票的价格数组，其中第i个元素就是该股票第i天的价格。
设计一个算法来计算能获取的最大利润。允许多次买卖一支股票，但不能同时参与多笔交易（必须在再次购买前出售掉之前的股票）。

思路：
一天内可以先卖出，再买进，所以问题可以简化为，只要后一天股价比前一天高，就可以先买后卖。
因此，两个两个地遍历数组，如果明天比今天价格高，那么今天就买入；否则就继续看明天和后天的价格。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};