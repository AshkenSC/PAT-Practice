/*
0110. Balanced Binary Tree

给定一个二叉树，判断它是否是高度平衡的二叉树。

思路1：遍历整个树，检测以树中每个结点为根的子树的高度，以及该点的左右子树的高度差。
一旦发现有高度差大于1的，设布尔值balanced为true。
这个方法的问题在于，发现了高度差大于1，却不能及时结束递归返回。

思路2：和思路1基本相同，主要区别在于，一旦发现子树有不平衡，直接返回-1来表示不平衡。
*/

#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool balanced = true;

    int traverse(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else {
            int leftHeight = traverse(node->left);
            int rightHeight = traverse(node->right);
            if (abs(leftHeight - rightHeight) > 1)
                balanced = false;
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        traverse(root);
        return balanced;
    }
};

class Solution {
public:
    int traverse(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else {
            // 只要左右子树有高度差大于1的，就返回-1
            // 否则，就返回当前高度差
            // 左右子遍历都要判定一次，尽可能减少递归。
            int leftHeight = traverse(node->left);
            if (leftHeight == -1)
                return -1;
            int rightHeight = traverse(node->right);
            if (rightHeight == -1)
                return -1;
            if (abs(leftHeight - rightHeight) > 1)
                return -1;
            else
                return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return traverse(root) != -1;
    }
};
