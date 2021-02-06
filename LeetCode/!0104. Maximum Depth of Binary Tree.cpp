/*
0104. Maximum Depth of Binary Tree

给定一个二叉树，确定其最大深度。

思路1：
层序遍历该树，将结点入队，并设置一个哨兵结点，每次遍历完一层就出队一次，并计数。

对指针和指针指向的对象有些生疏和混淆。

二刷，思路2：
采用从543题解学到的方法，递归求解。
如果是空节点，返回0；
如果是非空节点，返回左右孩子最大深度中更大的那个+1。这样深度就一层层建立起来。
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // 初始化哨兵结点，并设置一个左孩子作为其标志
        TreeNode sentinal = TreeNode(0);
        TreeNode sentinalLeft = TreeNode(114514);
        sentinal.left = &sentinalLeft;

        queue<TreeNode*> q;
        q.push(root);
        q.push(&sentinal);

        TreeNode* currentNode;
        while (!(q.size() == 1 && q.front() == &sentinal)) {
            currentNode = q.front();
            q.pop();
            if (currentNode == &sentinal) {
                sentinal.val = sentinal.val + 1;
                q.push(&sentinal);
            }
            else {
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
        }

        return sentinal.val + 1;
    }
};