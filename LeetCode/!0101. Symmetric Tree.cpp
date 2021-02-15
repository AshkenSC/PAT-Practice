/*
0101. Symmetric Tree

判断一个树是不是对称的。初步思路：设计一个递归函数，里面有两个子递归过程：
1）遍历左子树的左和右子树的右,只要有一层不相等，就返回false；
2）遍历左子树的右和右子树的左，只要有一层不相等，就返回false。

注意：
1）都等于nullptr也合法。
2）一开始算法设计错误，针对上述两个子递归过程分别设计了两个递归函数。
结果对1）的子树就只搜索他的左子树左和右子树右，对2）子树就只搜索他的左子树的右和右子树的左。

*/

// 二刷
// 绝大部分是自己写，但是被提醒了核心思想：左子树左=右子树右，且左子树右=右子树左
class Solution {
public:
    bool checkSymmetric(TreeNode *a, TreeNode *b) {
        if (a == nullptr || b == nullptr) {
            if (a == nullptr && b == nullptr)
                return true;
            else
                return false;
        }

        return (a->val == b->val) && checkSymmetric(a->left, b->right) && checkSymmetric(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return checkSymmetric(root->left, root->right); 
    }
};

// 一刷
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        TreeNode* leftChildren = root->left;
        TreeNode* rightChildren = root->right;

        // 左右子树都有
        if (leftChildren != nullptr && rightChildren != nullptr &&
            leftChildren->val == rightChildren->val) {
            if (compare(leftChildren->left, rightChildren->right) &&
                compare(leftChildren->right, rightChildren->left)) {
                return true;
            }
            else {
                return false;
            }
        }
        // 只有一个根节点
        else if(leftChildren == nullptr && rightChildren == nullptr) {
            return true;
        }
        // 只有左子树/只有右子树
        else {
            return false;
        }
    }

    bool compare(TreeNode* node1, TreeNode* node2) {
        // 两个结点都为空
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        // 两个结点都非空，比较val，相同则继续深入比较，不同则直接返回false
        else if (node1 != nullptr && node2 != nullptr) {
            if (node1->val == node2->val) {
                return compare(node1->left, node2->right) && compare(node1->right, node2->left);
            }
            else {
                return false;
            }
        }
        // 一个为空，一个非空
        else {
            return false;
        }
    }


};