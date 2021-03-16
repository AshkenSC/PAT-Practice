/*
剑指 Offer 55 - I. 二叉树的深度

输入一棵二叉树的根节点，求该树的深度。

思路：用一个值记录最大深度。然后深度遍历左右子树，不断更新该最大值。
*/

class Solution {
private:
    int maxDepthValue = 0;

    void getMaxDepth(TreeNode *node, int currentDepth) {
        if (node == nullptr) {
            return;
        }
        maxDepthValue = max(++currentDepth, maxDepthValue);
        getMaxDepth(node->left, currentDepth);
        getMaxDepth(node->right, currentDepth);
    }

public:
    int maxDepth(TreeNode* root) {
        getMaxDepth(root, 0);
        return maxDepthValue;
    }
};
