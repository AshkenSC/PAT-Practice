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
private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(vector<int>& candidates, int target, int currentSum, int startIndex) {
        // 如果加上当前数大于目标和，退出
        if (currentSum > target)
          return;
        // 如果加上当前数正好等于目标和，将当前path存入结果中，退出
        if (currentSum == target) {
          result.push_back(path);
          return;
        }

        // 递归实现回溯
        for (int i = startIndex; i < candidates.size(); i++) {
          currentSum += candidates[i];
          path.push_back(candidates[i]);
          // 加上当前结点以后，树继续向下分支
          backtracking(candidates, target, currentSum, i);   // 这里i不+1，是因为当前数字可以重复使用
          // 减去当前结点的值，并从path删除当前结点，让path回到之前的状态，便于下一轮兄弟结点操作
          currentSum -= candidates[i];
          path.pop_back();
        }
      }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      backtracking(candidates, target, 0, 0);
      return result;
    }
};