/*
剑指 Offer 07. 重建二叉树

从中序和前序构建二叉树。

思路：参考105题。

*/

// 三刷
/*
先序的第一个点就是根节点
在中序中，根节点左右分别是左子树和右子树
可以考虑先构建一个映射，这样可以方便地在中序遍历中找到每个节点的位置
*/

class Solution {
private:
    map<int, int> nodeIndex;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight,
                    int inorderLeft, int inorderRight) {
        // 递归的尽头，返回空节点
        if (preorderLeft > preorderRight) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderLeft]);
        int inOrderPos = nodeIndex[preorder[preorderLeft]];
        // 不要错写成inOrderPos - preOrderLeft ！！
        int leftTreeSize = inOrderPos - inorderLeft;
        root->left = build(preorder, inorder, preorderLeft + 1, preorderLeft + leftTreeSize, inorderLeft, inOrderPos - 1);
        root->right = build(preorder, inorder, preorderLeft + leftTreeSize + 1, preorderRight, inOrderPos + 1, inorderRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构建映射，便于在中序数组中找到节点位置
        for (int i = 0; i < inorder.size(); ++i) {
            nodeIndex[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

// 二刷，牛客网
class Solution {
private:
    unordered_map<int, int> occur;
public:
    TreeNode* build(vector<int>& pre, vector<int>& vin, 
                    int preLeft, int preRight, int vinLeft, int vinRight) {
        int rootInMidPos = occur[pre[preLeft]];
        int leftTreeSize = rootInMidPos - vinLeft;
        int rightTreeSize = vinRight - rootInMidPos;
        
        TreeNode *node = new TreeNode(pre[preLeft]);
        if (leftTreeSize > 0)
            node->left = build(pre, vin, preLeft + 1, preLeft + leftTreeSize, vinLeft, rootInMidPos - 1);
        if (rightTreeSize > 0)
            node->right = build(pre, vin, preLeft + leftTreeSize + 1, preRight, rootInMidPos + 1, vinRight);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int> pre,vector<int> vin) {
        // 遍历中序数组，记录出现位置
        for (int i = 0; i < vin.size(); ++i) {
            occur[vin[i]] = i;
        }
        
        TreeNode *node = build(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
        return node;
    }
};
