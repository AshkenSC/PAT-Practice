/*
0098. Validate Binary Search Tree

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

思路：迭代法中序遍历。用一个数prev记录上一个数。一旦出现cur < prev，就返回false。
注意测试用例取了一些边界值。可以考虑直接上long，也可以设一个flag记录首次访问。
*/


#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long preNum = -LONG_MAX - 1;

        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            // 判断当前数是否小于上一个数。如果小于，直接判断false
            if (root->val <= preNum) {
                return false;
            }
            preNum = root->val;
            // 移动到右孩子
            root = root->right;
        }

        return true;
    }
};
