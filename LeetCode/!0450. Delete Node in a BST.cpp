/*
0450. Delete Node in a BST

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。


思路：

一开始我想复杂了，以为是要求二叉平衡搜索树，但其实并不要求平衡。

参考https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/chao-xiang-xi-zhu-shi-ji-bai-9951-9896-b-2dqs/

0，到达叶子节点还没找到，返回null
1，比当前节点大，向右孩子找
2，比当前节点小，向左孩子找
3，正好等于这个节点，删除。
    3.1 删除的节点是叶子节点，直接删除
    3.2 删除的叶子节点只有左（右）孩子，用独生子代替被删除节点
    3.4 删除的叶子节点同时有左右孩子，将左子树移动到右子树的左叶子位置
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            else if (root->right == nullptr) {
                return root->left;
            }
            // 删除的节点左右孩子双全
            // 将左孩子挂到右孩子的左子树
            else {
                // 通过循环找到要挂root->left的位置，也就是右孩子的左叶子结点
                TreeNode *rtChild = root->right;
                while (rtChild->left != nullptr) {
                    rtChild = rtChild->left;
                }
                // 将root->left挂到新位置
                rtChild->left = root->left;

                // 删除节点
                TreeNode *temp = root;
                // 要返回的是删除节点的右孩子
                root = root->right;
                delete temp;
                return root;
            }
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};