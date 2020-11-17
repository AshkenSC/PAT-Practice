/*
0111. Minimum Depth of Binary Tree

给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

思路：DFS

*/

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
    int res = INT_MAX;

    void traverse(TreeNode* node, int currentDepth) {
        if (node == nullptr)
            return;
        else {
            currentDepth++;
            if (node->left == nullptr && node->right == nullptr) {
                if (currentDepth < res) {
                    res = currentDepth;
                }
                return;
            }
            else {
                traverse(node->left, currentDepth);
                traverse(node->right, currentDepth);
            }
        }
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        traverse(root, 0);
        return res;
    }
};

