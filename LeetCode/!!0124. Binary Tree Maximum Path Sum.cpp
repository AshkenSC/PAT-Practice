/*
0124. Binary Tree Maximum Path Sum

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。

思路：参考这个页面的最高赞评论。
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/

思路：自底向上。
递归函数向父节点返回以当前节点作为单边路径起点的最大值。（也就是，选择node + leftMax, node + righMax更大者）
同时，在递归函数内部，还要以当前节点作为”根“节点（也就是可以同时取左右孩子的节点），和历史最大值对比并更新之。

*/

class Solution {
public:
    int res = -INT_MAX;

    // 返回值：当前节点向下的单边分支的最大值（即当前节点看作不是max路径的“根”节点）
    // 注意：这里的“根”节点指的是路径中可以同时取左右孩子路径的节点。这个点在路径中只能有一个。
    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        // 计算当前节点左右孩子能取得的最大值
        int leftMax = max(0, dfs(node->left));
        int rightMax = max(0, dfs(node->right));

        // 假设当前节点就是路径“根”节点，将这条路径与记录中最大值对比。如果更大则更新之
        res = max(res, node->val + leftMax + rightMax);
        
        // 向父节点返回自己作为单边分支能提供的最大值
        return node->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        dfs(root);

        return res;
    }
};
