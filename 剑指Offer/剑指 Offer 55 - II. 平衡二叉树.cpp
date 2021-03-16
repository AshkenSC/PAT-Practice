/*
剑指 Offer 55 - II. 平衡二叉树

输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

思路：
遍历整个树，检测以树中每个结点为根的子树的高度，以及该点的左右子树的高度差。
一旦发现左子树或者右子树有不平衡，直接返回-1来表示不平衡。
*/

class Solution {
private:
    int getDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = getDepth(node->left);
        if (leftDepth == -1) {
            return -1;
        }
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1) {
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        else {
            return max(leftDepth, rightDepth) + 1;
        }
    }

public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};
