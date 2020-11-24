/*
0230. Kth Smallest Element in a BST

给定一个二叉搜索树，找里面第k大的元素。

思路：用迭代法找第k个。用一个数cnt记录现在是第几个数。当cnt==k时，输出结果。

*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;

        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            cnt++;
            if (cnt == k)
                return root->val;
            root = root->right;
        }

        return 0;
    }
};