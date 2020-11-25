/*
0110. Balanced Binary Tree

给定一个二叉树，判断它是否是高度平衡的二叉树。

思想：遍历整个树，检测以树中每个结点为根的子树的高度，以及该点的左右子树的高度差。
一旦发现有高度差大于1的，设布尔值balanced为true。
这个方法的问题在于，发现了高度差大于1，却不能及时结束递归返回。
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

class Solution {
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
