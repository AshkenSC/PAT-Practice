/*
0120. Triangle

给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

这题实际上给出的是一个直角三角形。只能向下或者向右走。
1）在原点
dp{i]{j] = dp[i][j]
2）只能从上来
dp[i][j] = dp[i - 1][j]
3）只能从左上来
dp[i][j] = dp[i - 1][j - 1]
4）可从左上or上来
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1])

参考：
https://leetcode-cn.com/problems/triangle/solution/javadong-tai-gui-hua-si-lu-yi-ji-dai-ma-shi-xian-b/
*/


class Solution {
public:
    static bool cmp(int a, int b) {
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
                else if (i == 0) {
                    triangle[i][j] = triangle[i][j - 1];
                }
                else if (j == triangle[i - 1].size() - 1) {
                    triangle[i][j] = triangle[i - 1][j];
                }
                else {
                    triangle[i][j] = min(triangle[i - 1][j], triangle[i][j - 1]);
                }
            }
        }

        sort(triangle[m - 1].begin(), triangle[m - 1].end(), cmp);
        return triangle[m - 1][0];
    }
};