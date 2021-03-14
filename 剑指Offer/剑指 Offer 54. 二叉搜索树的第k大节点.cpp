/*
剑指 Offer 54. 二叉搜索树的第k大节点

给定一棵二叉搜索树，请找出其中第k大的节点。

思路：中序遍历（注意先右后左）
*/

class Solution {
private:
    int current = 0;
    int result;

    void traverse(TreeNode* root, int k) {
        if (root == nullptr || current == k) {
            return;
        }

        // 遍历右子树
        if (root->right != nullptr) {
            traverse(root->right, k);
        }
        // 检查根节点
        // 如果当前已经超过第k个，直接结束遍历
        if (current > k) {
            return;
        }
        // 如果当前正好第k个，记录结果并结束遍历
        else if (++current == k) {
            result = root->val;
            return;
        }
        // 否则继续遍历左子树
        else {
            traverse(root->left, k);
            return;
        }
        
    }

public:
    int kthLargest(TreeNode* root, int k) {
        traverse(root, k);
        return result;
    }
};
