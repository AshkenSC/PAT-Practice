/*
0145. Binary Tree Postorder Traversal

给定一个二叉树，返回它的 后序 遍历。

*/

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 迭代遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;

        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev == root->right || root->right == nullptr) {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else {
                s.emplace(root);
                root = root->right;
            }
        }

        return res;
    }
};

// 递归遍历
class Solution {
public:
    vector<int> res;

    void traverse(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr)
            traverse(node->left);
        if (node->right != nullptr)
            traverse(node->right);

        res.emplace_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};
