/*
0077. Combinations

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

思路：回溯法经典题！
参考https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
*/

#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int n, int k, int begin, vector<int> path, vector<vector<int>> &res) {
        // 递归的终点，路径长度达到要求，保存结果
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // 尝试每个可能的路径
        for (int i = begin; i <= n; i++) {
            // 将当前数添加到路径中
            path.push_back(i);
            // dfs遍历。由于要求数字不重复，因此下一层起点从i+1开始。
            backtrack(n, k, i + 1, path, res);
            // 回溯
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        // 处理非法输入
        if (k <= 0 || n < k) {
            return res;
        }

        // 回溯法求解
        // 根据题目要求，从1开始
        backtrack(n, k, 1, vector<int>(), res);
        return res;
    }
};

