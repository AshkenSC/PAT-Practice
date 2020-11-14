/*
0257. Binary Tree Paths

给定一个二叉树，返回所有从根节点到叶子节点的路径。

思路：深度优先
*/

#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> res;

    void traverse(TreeNode* node, string route) {
        route = route + "->" + to_string(node->val);
        // 到达叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(route);
            return;
        }
        else {
            if (node->left != nullptr) {
                traverse(node->left, route);
            }
            if (node->right != nullptr) {
                traverse(node->right, route);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return res;
        else if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string(root->val));
            return res;
        }
        else {
            if (root->left != nullptr)
                traverse(root->left, to_string(root->val));
            if (root->right != nullptr)
                traverse(root->right, to_string(root->val));
            return res;
        }
    }
};
