/*
0230. Kth Smallest Element in a BST

给定一个二叉搜索树，找里面第k大的元素。

思路：用迭代法找第k个。用一个数cnt记录现在是第几个数。当cnt==k时，输出结果。

*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 记录当前是第几大的数。当cnt==k，输出结果
        int cnt = 0;
        stack<TreeNode*> s;

        // 中序遍历BST
        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            cnt++;
            // 当cnt==k，输出结果
            if (cnt == k)
                return root->val;
            root = root->right;
        }

        // 其实走不到这里，单纯为了符合力扣语法要求
        return 0;
    }
};