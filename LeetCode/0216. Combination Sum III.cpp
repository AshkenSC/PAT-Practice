/*
0216. Combination Sum III

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。 
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curCombination;

    void backtrack(int k, int n, int curSum, int startIndex) {
        // 当前和等于目标和，且候选数个数符合，保存结果并退出
        if (curSum == n && curCombination.size() == k) {
            res.push_back(curCombination);
            return;
        }
        // 当前和大于目标和，或当前候选数超过k个，直接退出
        if (curSum > n || curCombination.size() > k)
            return;
        // 当前和小于目标和，继续寻找
        for (int i = startIndex; i <= 9; i++) {
            curCombination.push_back(i);
            curSum += i;
            // 递归找组合，注意候选数字为i+1，因为不允许有重复数字
            backtrack(k, n, curSum, i + 1);
            // 回溯
            curCombination.pop_back();
            curSum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // 只允许正整数，因此候选从1开始
        backtrack(k, n, 0, 1);
        return res;
    }
};

