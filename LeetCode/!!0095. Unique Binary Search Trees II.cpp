/*
0095. Unique Binary Search Trees II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

思路：一开始考虑用回溯法，但难以排除重复情况。
然后参考了这个
https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-7/
采用分治递归法
*/

#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> getAns(int start, int end) {
        vector<TreeNode *> ans;
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }
        if (start == end) {
            TreeNode *tree = new TreeNode(start);
            ans.push_back(tree);
            return ans;
        }
        for (int i = start; i <= end; i++) {
            // 得到所有可能的左右子树
            vector<TreeNode *> left = getAns(start, i - 1);
            vector<TreeNode *> right = getAns(i + 1, end);
            // 将所有左右子树组合
            for (auto leftTree : left) {
                for (auto rightTree : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    // 将当前结果加入结果列表
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> ans;
        if (n == 0)
            return ans;
        return getAns(1, n);
    }
};
