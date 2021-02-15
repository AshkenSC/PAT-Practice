/*
0144. Binary Tree Preorder Traversal

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

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

// 递归解法
class Solution {
public:
    vector<int> res;

    void traverse(TreeNode *node) {
        if (node == nullptr)
            return;
        res.push_back(node->val);
        traverse(node->left);
        traverse(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};

// 迭代解法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode*> s;
        s.emplace(root);
        while (s.empty() == false) {
            TreeNode *currentNode = s.top();
            s.pop();
            res.push_back(currentNode->val);

            if (currentNode->right)
                s.emplace(currentNode->right);
            if (currentNode->left)
                s.emplace(currentNode->left);
        }

        return res;
    }
};
