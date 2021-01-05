#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change
/*
这题实际上给出的是一个直角三角形。只能向下或者向右走。
1）在原点
dp{i]{j] = dp[i][j]
2）只能从上来
dp[i][j] = dp[i - 1][j]
3）只能从左上来
dp[i][j] = dp[i - 1][j - 1]
4）可从左上or上来
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1])


*/

class Solution {
public:
    static bool cmp(int &a, int &b) {
        return a > b;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // vector<vector<int>> dp;
        // // 构造一个大小和triangle一样的dp数组。但其实根本不用构造，直接修改triangle即可。
        // dp.resize(m);
        // for (int i = 0; i < m; i++) {
        //     dp[i].resize(triangle[i].size());
        // }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == 0 && j == 0)
                    continue;
                else if (j == 0) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
                }
                else if (j == i) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }

        int min = triangle[m - 1][0];
        for (auto num : triangle[m - 1]) {
            if (num < min) {
                min = num;
            }
        }

        return min;
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
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> input = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = sol.minimumTotal(input);
    cout << res;

    return 0;
}