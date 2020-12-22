/*
剑指 Offer 34. 二叉树中和为某一值的路径

输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

思路：回溯法。
注意：必须到根节点，才算一整个路径。如果在中途得到和了，不算路径！
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curPath;

    void backtrack(TreeNode* node, int sum, int curSum) {
        if (curSum == sum && node->left == nullptr && node->right == nullptr) {
            res.emplace_back(curPath);
            return;
        }
        else {
            if (node->left != nullptr) {
                curPath.push_back(node->left->val);
                backtrack(node->left, sum, curSum + node->left->val);
                curPath.pop_back();
            }
            if (node->right != nullptr) {
                curPath.push_back(node->right->val);
                backtrack(node->right, sum, curSum + node->right->val);
                curPath.pop_back();
            }
        }
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return res;
        
        curPath.push_back(root->val);
        backtrack(root, sum, root->val);
        return res;
    }
};
