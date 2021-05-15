/*
剑指 Offer 27. 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

思路：
一开始卡壳了，没有想到用临时变量暂存。
*/

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        auto temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);

        return root;
    }
};
