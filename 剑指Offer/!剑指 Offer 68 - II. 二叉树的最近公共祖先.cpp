/*
剑指 Offer 68 - II. 二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

思路：
1）p q有一个为当前root
2）p q同在root的左or右子树
3）p q分列左右子树
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }
        else if (left != nullptr) {
            return left;
        }
        else if (right != nullptr) {
            return right;
        }

        // 注意，这里结尾要返回nullptr，而不是root
        return nullptr;
    }
};
