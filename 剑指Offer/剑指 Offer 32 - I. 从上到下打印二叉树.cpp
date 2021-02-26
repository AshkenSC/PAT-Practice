/*
剑指 Offer 32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

思路：层序遍历。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false) {
            TreeNode *temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if (temp->left != nullptr) {
                q.emplace(temp->left);
            }
            if (temp->right != nullptr) {
                q.emplace(temp->right);
            }
        }

        return res;
    }
};
