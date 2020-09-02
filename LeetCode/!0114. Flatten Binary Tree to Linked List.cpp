/*
0114. Flatten Binary Tree to Linked List

给定一个二叉树，原地将它展开为一个单链表。

思路：
1）先找到root左子树最右侧的叶子节点；
2）将root的右子树，作为1）找到的节点的右孩子；
3）将经过2）修改后的左子树，作为root的右子树；
4）将root左子树设为空；
5）root = root.right，重复循环。
*/


class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            // 找到root左子树最右侧的叶子结点
            TreeNode* pre = root->left;
            if (pre == nullptr)
                root = root->right;
            else {
                while (pre->right != nullptr)
                    pre = pre->right;
                // 将当前root的右子树，作为上面找到的结点的右孩子
                pre->right = root->right;
                // 将当前root的左子树赋给当前root的右孩子
                root->right = root->left;
                root->left = nullptr;
                // 考虑root的下一个右孩子
                root = root->right;
            }
        }
    }
};