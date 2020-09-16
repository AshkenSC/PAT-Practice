/* 
0236. Lowest Common Ancestor of a Binary Tree

给定一个二叉树，和树中的两个结点，找到他们的最进公共祖先。（一个结点最近公共祖先可以是其本身）

后序遍历：
1. left和right同时为空：说明left和right都不p或q，返回null
2. left和right同时不为空，说明left和right各包含一个p或q，返回当前root
3. left为空，right不为空，说明right中同时包含p或q，返回right
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return root; 
    }
};