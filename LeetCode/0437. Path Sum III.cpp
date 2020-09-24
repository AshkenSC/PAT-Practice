/*
0437. Path Sum III

给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

思路1：暴力解法
以每个结点为根节点，计算路径和为sum的有多少条

*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution1 {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int helper(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int helper(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        // 每次路过一个结点，就用sum减去当前根结点的值，然后看看sum是否为0
        // 如果为0了，说明路径结束了，当前路径就是一条可行路径的终点
        // 同时，也继续查看当前结点的左右结点是不是可行路径的终点
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
};
