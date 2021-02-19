/*
剑指 Offer 07. 重建二叉树

从中序和前序构建二叉树。

思路：参考105题。

*/

class Solution {
public:
    unordered_map<int, int> index;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                    int pre_start, int pre_end, int in_start, int in_end) {
        // 递归的终点
        if (pre_start > pre_end) {
            return nullptr;
        }
        // 找到当前节点在前序和中序数组的位置
        int pre_pos = pre_start;
        int in_pos = index[preorder[pre_pos]];
        // 建立新节点
        TreeNode* node = new TreeNode(preorder[pre_pos]);
        // 递归构建节点的左右子树
        int leftSize = in_pos - in_start;
        node->left = build(preorder, inorder, pre_start + 1, pre_start + leftSize, in_start, in_pos - 1);
        node->right = build(preorder, inorder, pre_start + leftSize + 1, pre_end, in_pos + 1, in_end);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构建一个根据前序遍历中节点值，找到其在中序遍历数组位置的字典
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i; 
        }

        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
