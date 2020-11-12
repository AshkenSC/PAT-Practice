/*
0563. Binary Tree Tilt

给定一个二叉树，计算 整个树的坡度 。
一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
如果没有左子树的话，左子树的节点之和为0 ；没有右子树的话也是一样。空结点的坡度是 0 。
整个树 的坡度就是其所有节点的坡度之和。

思路：
哎，其实不难，但我还是不熟悉，被自己搞复杂了……
https://leetcode-cn.com/problems/binary-tree-tilt/solution/er-cha-shu-de-po-du-0ms-by-zui-weng-jiu-xian/
还有一个原因是，我总觉得辅助递归函数如果有返回值，在最外层调用时就一定要“用上”，其实不是。

用递归计算出左子树和右子树的和，得到左右子树的差，立刻更新存储最终结果的变量。
递归函数返回当前树和（包括当前结点+左子树和+右子树和）
*/

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int tilt = 0;

    int getTilt(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int leftSum = getTilt(node->left);
        int rightSum = getTilt(node->right);
        tilt += abs(leftSum - rightSum);
        return node->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        getTilt(root);
        return tilt;
    }
};