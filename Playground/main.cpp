#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (abs(sum) < abs(S)) {
            return 0;
        }

        int len = nums.size();
        int range = sum * 2 + 1;
        vector<vector<int>> dp(len, vector<int>(range));
        if (nums[0] == 0) {
            dp[0][sum] = 2;
        }
        else {
            dp[0][sum + nums[0]] = 1;
            dp[0][sum - nums[0]] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < range; j++) {
                // 边界
                int l = (j - nums[i]) > 0 ? (j - nums[i]) : 0;
                int r = (j + nums[i]) < range ? (j + nums[i]) : 0;
                dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
            }
        }

        return dp[len - 1][sum + S];
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