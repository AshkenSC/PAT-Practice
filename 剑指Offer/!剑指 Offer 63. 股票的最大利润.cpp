/*
剑指 Offer 63. 股票的最大利润

动态规划经典基础题！但还是不会！！

假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
*/

/*
dp[i] = max(dp[i - 1], prices[i] - minPrice)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        } 

        int dpI = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i - 1]);
            dpI = max(dpI, prices[i] - minPrice);
        }

        return dpI;
    }
};
