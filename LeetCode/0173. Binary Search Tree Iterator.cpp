/*
0173. Binary Search Tree Iterator

实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
调用 next() 将返回二叉搜索树中的下一个最小的数。

next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。

思路：根据迭代法中序遍历改写而成，只不过每调用一次next才执行一次循环体。
不过，这样符合空间复杂度要求吗？
*/

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    TreeNode *node;
    stack<TreeNode *> s;

    BSTIterator(TreeNode* root) {
        node = root;

        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int value;

        while (node != nullptr) {
            s.emplace(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        value = node->val;  // 记录要返回的值
        node = node->right;
        return value;       // 返回值
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (node != nullptr || s.empty() == false)
            return true;
        else
            return false;
    }
};
