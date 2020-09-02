/*
0094. Binary Tree Inorder Traversal

实现二叉树的中序遍历。
*/

class Solution {
public:
    vector<int> result;

    void traverse(TreeNode* node) {
         if (node->left != NULL)
            inorderTraversal(node->left);
        result.push_back(node->val);
        if (node->right != NULL)
            inorderTraversal(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return result;
        traverse(root);
        return result;
    }
};