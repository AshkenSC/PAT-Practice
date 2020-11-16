/*
0112. Path Sum

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

思路：深度优先遍历。
在非叶子结点，深度优先遍历。
如果在叶子结点，路径和等于目标和，doExist设为true，返回。
如果在叶子结点，路径和不等于目标和，则返回。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool doExist = false;

    void traverse(TreeNode* node, int currentSum, int sum) {
        // 已经找到，不必再找了
        if (doExist)
            return;
        // 当前结点是叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            if (currentSum + node->val == sum) {
                doExist = true;
            }
            return;
        }
        // 当前结点是非叶子节点
        else {
            if (node->left != nullptr) {
                traverse(node->left, currentSum + node->val, sum);
            }
            if (node->right != nullptr) {
                traverse(node->right, currentSum + node->val, sum);
            }
        }
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;

        traverse(root, 0, sum);
        return doExist;
    }
};
