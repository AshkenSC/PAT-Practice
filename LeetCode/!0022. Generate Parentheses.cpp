/*
0022. Generate Parentheses

给定n对括号，写一个函数生成所有有效的括号组合。例如，给定n=3，解集为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

思路：回溯法（深度优先遍历结果树进行枚举 + 按题目要求剪枝）
满足条件：左右括号数量相等，都为n。当左括号小于右括号数量，或者左/右括号数量大于n，则停止深度探索，return
*/

class Solution {
    public:
        void dfs(vector<string>& result, string current, int n, int left_bracket, int right_bracket) {
            // 如果是这几种情况，则不再向下深度遍历
            if (left_bracket < right_bracket || left_bracket > n || right_bracket > n)
                return;
            // 满足条件，加入解集
            if (left_bracket == right_bracket && left_bracket == n) {
                result.push_back(current);
                return;
            }
            // dfs遍历
            dfs(result, current + '(', n, left_bracket + 1, right_bracket);
            dfs(result, current + ')', n, left_bracket, right_bracket + 1);
        }

        vector<string> generateParenthesis(int n) {
            vector<string> result;
            dfs(result, "", n, 0, 0);
            return result;
        }
};