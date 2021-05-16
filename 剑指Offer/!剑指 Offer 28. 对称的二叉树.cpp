/*
剑指 Offer 28. 对称的二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

思路：
做过的题，又卡壳了。
用一个单独变量记录是否对称。一旦发现不对称，立即设为false，且后面都不用判断了。
递归过程中不断比较当前左子树val == 右子树val，以及当前右子树val == 左子树val。
注意处理空节点情况。
*/

class Solution {
private:
    bool flag = true;

public:
    void check(TreeNode* a, TreeNode* b) {
        if (flag == false || (a == nullptr && b == nullptr)) {
            return;
        }

        if (a && b && a->val == b->val) {
            check(a->left, b->right);
            check(a->right, b->left);
        }
        else {
            flag = false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        check(root->left, root->right);
        return flag;
    }
};
