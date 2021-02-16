/*
0958. Check Completeness of a Binary Tree

给定一个二叉树，确定它是否是一个完全二叉树。

思路：参考评论区代码。
层序遍历，设置一个停止标志，遇到空节点，停止标志为真。
如果停止标志为真，再遍历遇到非空节点，则非完全二叉树。

*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool notComplete = false;
        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false) {
            auto currentNode = q.front();
            q.pop();

            if (currentNode->left == nullptr) {
                notComplete = true;
            }
            else {
                if (notComplete)
                    return false;
                else
                    q.emplace(currentNode->left);
            }

            if (currentNode->right == nullptr) {
                notComplete = true;
            }
            else {
                if (notComplete)
                    return false;
                else
                    q.emplace(currentNode->right);
            }
        }
    
        return true;
    }
};
