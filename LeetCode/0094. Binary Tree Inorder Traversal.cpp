/*
0094. Binary Tree Inorder Traversal

实现二叉树的中序遍历。
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

class Solution {
public:
    vector<int> result;

    void traverse(TreeNode* node) {
         if (node->left != NULL)
            inorderTraversal(node->left);
        result.push_back(node->val);
        if (node->right != NULL)
            inorderTraversal(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return result;
        traverse(root);
        return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> s;
        while (s.empty() == false || root != nullptr) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }
};
