/*
0121. Best Time to Buy and Sell Stock

给定一个某股票的价格数组，其中第i个元素就是该股票第i天的价格。
如果最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算能获取的最大利润。

思路：动态规划。
1）记录第i天之前买入的最小值;
2）计算：如果在第i天之前的最小值买入，并在第i天卖出的利润，得到第i天的最大利润;
3）对比每一天的最大利润，得到结果。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfitValue = 0;

        if (prices.size() < 2) {
            return 0;
        }

        for (int i = 1; i < prices.size(); ++i) {
            maxProfitValue = max(maxProfitValue, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfitValue;
    }
};
