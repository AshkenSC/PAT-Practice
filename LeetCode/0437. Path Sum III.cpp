/*
0437. Path Sum III

给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

思路1：暴力解法
以每个结点为根节点，计算路径和为sum的有多少条

思路2：回溯
参考：https://leetcode-cn.com/problems/path-sum-iii/solution/qian-zhui-he-di-gui-hui-su-by-shi-huo-de-xia-tian/
用字典记录下从root到当前结点的路径的总和currentSum。然后检查当前字典中是否存在有路径总和为currentSum - target的结点。
如果存在有和为currentSum - target的结点，那么从那个结点开始，到当前结点位置，这一段路径的长度就是target。
以此模式深度遍历树，并回溯，从而得到结果。
*/

#include <map>
using namespace std;

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
    int recurSum(TreeNode* node, map<int, int> prefixSumCount, int target, int currentSum) {
        // 递归中止条件
        if (node == nullptr)
            return 0;
        // 统计从root到本结点存在多少条路径
        int res = 0;
        // 当前路径的和
        currentSum += node->val;

        // 查看当前路径是否存在和为currentSum - target的结点
        // 如果存在，则那些点就可看作路径的起点
        if (prefixSumCount.count(currentSum - target) != 0)
            res += prefixSumCount[currentSum - target];
        // 更新路径上当前结点前缀和的个数
        if (prefixSumCount.count(currentSum) != 0)
            prefixSumCount[currentSum] += 1;
        else
            prefixSumCount[currentSum] = 1;
        
        // 递归查找左右子树的情况
        res += recurSum(node->left, prefixSumCount, target, currentSum);
        res += recurSum(node->right, prefixSumCount, target, currentSum);

        // 返回上一层前，将状态回溯，去除当前结点的前缀和数量
        prefixSumCount[currentSum] -= 1;
        // 返回结果（从root到当前结点中包含多少条路径）
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        // key是前缀和，value是和为key的路径有多少条
        map<int, int> prefixSumCount;
        // 前缀和为0的一条路径
        prefixSumCount[0] = 1;
        // 回溯法求解
        return recurSum(root, prefixSumCount, sum, 0);
    }
};
