/*
0617. Merge Two Binary Trees

合并两棵二叉树。如果有两个结点重合，则重合位置结点是两结点值之和。

思路：
递归遍历，同时访问左孩子或同时访问右边孩子。
当前如果有一个结点为空，则立刻将另一个结点作为返回值。
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};