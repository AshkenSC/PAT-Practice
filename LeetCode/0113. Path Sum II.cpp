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

    void traverse(TreeNode* node, vector<int> currentPath, int currentSum, int sum) {
        // 如果当前结点是叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val + currentSum == sum) {
                currentPath.push_back(node->val);
                res.push_back(currentPath);
            }
            return;
        }
        // 如果当前结点是非叶子结点
        else {
            currentPath.push_back(node->val);
            if (node->left != nullptr)
                traverse(node->left, currentPath, currentSum + node->val, sum);
            if (node->right != nullptr)
                traverse(node->right, currentPath, currentSum + node->val, sum);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return res;

        vector<int> currentSum;
        traverse(root, currentSum, 0, sum);
        return res;
    }
};
