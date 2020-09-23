/*
0337. House Robber III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

思路：树的动态规划
https://leetcode-cn.com/problems/house-robber-iii/solution/shu-xing-dp-ru-men-wen-ti-by-liweiwei1419/

使用后序遍历，因为我们想让子结点层层汇报信息给父节点，
这样最后在根节点汇总结果。

定义状态：
dp[node][j]，node表示一个结点，
j表示node是否被抢。j=0表示不偷，j=1表示被偷。

状态转移：
如果当前结点偷，则左右子结点不能偷；
如果当前结点不偷，则左右子结点可以偷，也可以不偷，选最大的。

初始化：
空结点，返回0。

输出：
在根节点时，返回结果。
*/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            vector<int> arr(2);
            return arr;
        }

        // 因为是后序遍历，所以先计算左右子结点，然后计算当前结点状态
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        
        // dp[0]: 以当前node为根节点的子树能够偷取到的最大价值，且不偷node
        // dp[1]：以当前node为根节点的子树能够偷取到的最大价值，且偷node
        vector<int> dp(2);
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        dp[1] = node->val + left[0] + right[0];
        return dp;
    }

    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};