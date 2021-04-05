/*
剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

基础题！却又忘记怎么做了！！！真蠢！！！

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

思路：
1）如果在同一子树中（或同时大于当前节点，或同时小于当前节点），则继续在该子树向下找；
2）如果当前节点等于p或q，则公共祖先就是p或q；
3）如果p和q在两个子树中，则公共祖先就是当前节点。

注意：2）和3）可以合并为，直接返回当前root！我搞复杂了。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
