/*
0100. Same Tree


给定两个二叉树，写一个函数判断两者是否相同。相同二叉树指结构和对应位置的结点值都要相同。

分析：递归判断。
1）如果两棵树当前结点都非空且值相等，则进一步同时判断两者左子树和右子树是否相等，必须左右子树同时相等才返回true。
2）如果当前结点同时为空结点，则1）两棵树为空树，或者2）同时遍历到了空结点。此时都可以认为当前结点相等，返回true。
3）其他情况一律返回false。
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p != nullptr && q != nullptr && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
            return false;
        }
    }
};