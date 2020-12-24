#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 213. House Robber II

class Solution
{
public
    int minSteps(int n)
    {
        if (n <= 1)
            return 0;
        if (n <= 3)
            return n;
        int[] dp = new int[n + 1];
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
            dp[i] = i;
        for (int i = 2; i <= n; i++)
        {
            for (int mult = 2; multi <= n; mult++)
            {
                //每个格子都尝试去标记之后的自己可以到达的格子。对多种可能取最小。
                dp[multi] = Math.min(dp[mult * i], dp[i] + mult);
            }
        }
        return dp[n];
    }
}

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