/*
0687. Longest Univalue Path

给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

思路：
参考https://leetcode-cn.com/problems/longest-univalue-path/solution/guan-yu-di-gui-si-lu-de-chao-xiang-xi-ge-ren-jian-/
递归函数的作用：
1）找到以当前结点为开头的子路径的最长长度
2）如果以当前结点为根结点，满足左=根=右，计算该结构长度，如果超过记录长度，则更新。
*/

#include <algorithm>
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
    int maxLen;

    // 递归遍历，同时返回以此结点开头的子路径长度。
    int traverse(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int currentSubLen = 0;
        int left = traverse(node->left);
        int right = traverse(node->right);

        // 如果该结点作为根节点，满足左-根-右
        if (node->left != nullptr && node->left->val == node->val && 
        node->right != nullptr && node->right->val == node->val) {
                maxLen = max(maxLen, left + right + 2);
            }
        
        // 从左右子树中选择一个更长的作为子路径
        if (node->left != nullptr && node->val == node->left->val) {
            currentSubLen = left + 1;
        }
        if (node->right != nullptr && node->val == node->right->val) {
            currentSubLen = max(currentSubLen, right + 1);
        }

        // 更新路径最大值
        maxLen = max(maxLen, currentSubLen);
        return currentSubLen;
    }

    int longestUnivaluePath(TreeNode* root) {
        maxLen = 0;
        traverse(root);
        return maxLen;
    }
};