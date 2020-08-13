/*
0538. Convert BST to Greater Tree

给定一个二叉搜索树BST，将他转化为累加树，使得原来BST的每一个结点转为原来的值加上所有比他大的结点的值。

思路：BST的特点：左子小于结点小于右子。因此可以通过反向中序遍历，每次记录之前累加的值。
先经过右子树，因为右子树的结点最大；
再经过结点；最后经过左子树。
*/

class Solution {
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root != NULL) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};
