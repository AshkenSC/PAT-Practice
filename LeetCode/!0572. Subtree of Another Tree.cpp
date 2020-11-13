/*
0572. Subtree of Another Tree

给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

思路：
参考https://leetcode-cn.com/problems/subtree-of-another-tree/solution/java-di-gui-ban-by-kelly2018/

s是t的子树，有三种情况：
1）s是t的左子树；2）s是t的右子树；3）s和t完全相等。

而判断两个树完全相等，可以用递归实现：
1）根结点相等；2）左子树相等；3）右子树相等。
*/

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSametree(TreeNode *s, TreeNode *t) {
        // s和t都是空树
        if (s == nullptr && t == nullptr)
            return true;
        // s和t相等，要求根相等，左右子树相等
        else if (s != nullptr && t != nullptr &&
                s->val == t->val && isSametree(s->left, t->left) && 
                isSametree(s->right, t->right))
            return true;
        // 其他情况都不等
        else
            return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr)
            return false;
        if (t == nullptr)
            return true;
        // 递归检查
        return (isSubtree(s->left, t) || isSubtree(s->right, t) || isSametree(s, t));
    }
};