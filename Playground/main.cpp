#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    Solution sol;
    vector<int> input = {2, 3, 1, 1, 4};
    bool res = sol.canJump(input);
    cout << res;

    return 0;
}