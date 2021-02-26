/*
剑指 Offer 32 - III. 从上到下打印二叉树 III

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

思路1：用一个flag标记是顺序打印还是逆序打印。每打印一层翻转一次flag。

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        int direction = 1;
        while (q.empty() == false) {
            int qSize = q.size();
            vector<int> layer;
            for (int i = 0; i < qSize; ++i) {
                auto node = q.front();
                q.pop();
                layer.push_back(node->val);

                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            if (direction < 0) {
                reverse(layer.begin(), layer.end());
            }
            res.push_back(layer);
            direction = -direction;
        }

        return res;
    }
};
