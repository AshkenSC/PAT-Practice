/*
剑指 Offer 36. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。

关键是想通两个点：
1）想到用中序遍历
2）每次遍历，虽然修改两个指针，但是不是修改同一个节点的两个指针,而是修改pre的right，和cur的left！！

参考：
https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/
*/

class Solution {
public:
    Node *pre = nullptr;
    Node *head = nullptr;

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node *cur) {
        if (cur == nullptr) {
            return;
        }
        
        // 1）左子树
        dfs(cur->left);

        // 2）根节点
        if (pre != nullptr) {
            // 关键是想通两个点：
            // 1）想到用中序遍历
            // 2）每次遍历，虽然修改两个指针，但是不是修改同一个节点的两个指针
            // 而是修改pre的right，和cur的left！！
            cur->left = pre;
            pre->right = cur;
        }
        else {
            head = cur;
        }
        pre = cur;

        // 右子树
        dfs(cur->right);
    }
};
