/*
0039. Combination Sum.cpp

给定一系列候选数字（不重复）和一个目标数字。找到候选数字加起来等于目标数字的所有组合。
同一个候选数字可以被无限次地重复选择。

例如：
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

思路：动态规划和回溯法都可以求解。这里使用回溯法。
参考：https://leetcode-cn.com/problems/combination-sum/solution/39-zu-he-zong-he-hui-su-fa-jing-dian-ying-yong-xia/

建议先画出“决策树”，加深理解。由于这里是组合，不是排列，所以：
从根节点起，取2的分支下面可以有取2，3，6，7；
取3的分支下面只有取3，6，7（因为取2+3已经在取2的分支下面有过了）；
取6的分支下面只有取6，7（理由同上）。
而又因为题目说每个数可以无限制重复取，所以取完2还可以取2，取完3还可以取3。
*/

#include <vector>
using namespace std;

class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, 
    vector<vector<int>> &res, vector<int> curCombination, int curSum, int startIndex) {
        if (curSum == target) {
            res.push_back(curCombination);
            return;
        }
        if (curSum > target) {
            return;
        }
        // 继续递归求组合
        for (int i = startIndex; i < candidates.size(); i++) {
            curCombination.push_back(candidates[i]);
            // 这里startIndex保持不变，因为题目允许重复选择数字
            findCombinations(candidates, target, res, curCombination, curSum + candidates[i], i);
            // 回溯
            curCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        findCombinations(candidates, target, res, vector<int>(), 0, 0);
        return res;
    }
};

// 产生了一个典型错误写法
// 像这样写，虽然可以重复选取，但是也会导致相同组合重复出现！
// 最后输出结果是：[[2,2,3],[2,3,2],[3,2,2],[7]]
// 每一层需要记录起始的index，不然就会出现上面的错误。求”组合“变成求”排列“。
/*
class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, 
    vector<vector<int>>& res, vector<int> currentComb, int currentSum) {
        // 如果当前恰好等于目标值，保存结果并返回
        if (currentSum == target) {
            res.push_back(currentComb);
            return;
        }
        // 如果当前和大于目标值，返回
        else if (currentSum > target) {
            return;
        }
        // 如果当前和小于目标值，继续添加候选数字
        else {
            // 本题允许重复添加相同数字
            for (auto num : candidates) {
                currentComb.push_back(num);
                findCombinations(candidates, target, res, currentComb, currentSum + num);
                // 回溯
                currentComb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        findCombinations(candidates, target, res, vector<int>(), 0);
        return res;
    }
};
*/