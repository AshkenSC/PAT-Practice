/*
剑指 Offer 32 - II. 从上到下打印二叉树 II

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

思路：用两个队列轮流存储，从而分层。
*/

// 思路2：记录当前层节点个数，不需要双队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false) {
            int qSize = q.size();
            vector<int> layer;
            for (int i = 0; i < qSize; ++i) {
                auto node = q.front();
                q.pop();
                layer.push_back(node->val);

                if (node->left != nullptr) {
                    q.emplace(node->left);
                }
                if (node->right != nullptr) {
                    q.emplace(node->right);
                }
            }
            res.push_back(layer);
        }

        return res;
    }
};


// 思路1：双队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q1, q2;
        q1.emplace(root);
        
        while (q1.empty() == false || q2.empty() == false) {
            vector<int> layer1;
            while (q1.empty() == false) {
                auto node = q1.front();
                q1.pop();
                layer1.push_back(node->val);

                if (node->left) {
                    q2.emplace(node->left);
                }
                if (node->right) {
                    q2.emplace(node->right);
                }
            }
            res.push_back(layer1);

            vector<int> layer2;
            while (q2.empty() == false) {
                auto node = q2.front();
                q2.pop();
                layer2.push_back(node->val);

                if (node->left) {
                    q1.emplace(node->left);
                }
                if (node->right) {
                    q1.emplace(node->right);
                }
            }
            res.push_back(layer2);
        }
        if (res.back().size() == 0) {
            res.pop_back();
        }   

        return res;
    }
};
