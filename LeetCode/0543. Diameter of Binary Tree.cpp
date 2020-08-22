/*
0543. Diameter of Binary Tree

给定一个二叉树，你需要计算该树的直径长度。
二叉树的直径长度是指，树中两个结点最远路径的长度。
这个路径可能不通过根节点。

思路：以下是几个正确解答问题的关键：
1）路径长度为经过的结点数-1（植树问题！3棵树中间有2段路）
2）一个结点的孩子向下遍历经过的最多结点数就是这个孩子的深度。
3）一个树的最大路径结点数 = 左孩子最大路径结点数 + 右孩子最大路径结点数 + 1（它本身）
4）可以用递归，算出这棵树所有结点的最大路径结点数，只保留最大者。然后-1，即得到结果。
这题有很多小细节要注意。
*/

class Solution {
public:

    int res = 0;

    int getDepth(TreeNode* node) {
        if (node == NULL)
            return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        getDepth(root);
        return res - 1;
    }
};