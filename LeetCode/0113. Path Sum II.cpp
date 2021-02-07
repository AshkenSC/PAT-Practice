/*
0113. Path Sum II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

思路：深度优先遍历。
在非叶子结点，深度优先遍历。
如果在叶子结点，路径和等于目标和，保存当前路径，返回。
如果在叶子结点，路径和不等于目标和，则返回。
*/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;

    void traverse(TreeNode *node, int targetSum, int curSum, vector<int> curPath) {
        // 到达叶子节点
        if (node->left == nullptr && node->right == nullptr) {
            if (curSum == targetSum) {
                res.push_back(curPath);
            }
            return;
        }

        // 非叶子节点，dfs遍历
        if (node->left) {
            curPath.push_back(node->left->val);
            traverse(node->left, targetSum, curSum + node->left->val, curPath);
            curPath.pop_back();
        }
        if (node->right) {
            curPath.push_back(node->right->val);
            traverse(node->right, targetSum, curSum + node->right->val, curPath);
            curPath.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return res;
        }

        vector<int> curPath;
        curPath.push_back(root->val);
        traverse(root, targetSum, root->val, curPath);

        return res;
    }
};
