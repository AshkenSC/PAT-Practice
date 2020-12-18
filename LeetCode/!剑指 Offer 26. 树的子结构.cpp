/*
剑指 Offer 26. 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

思路：参考评论区。
*/

class Solution {
public:
    bool dfs(TreeNode* A, TreeNode* B) {
        if (B == NULL)
            return true;
        if (A == NULL)
            return false;
        return A->val == B->val && dfs(A->left, B->left) && dfs(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};