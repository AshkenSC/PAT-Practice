/*
0102. Binary Tree Level Order Traversal

给定一个二叉树，返回层序遍历的结点序列。

思路：
层序遍历不难，但要想出如何分层。
考虑在向队列中新加入元素之前，先记录当前队列的大小，也就是当前层结点数量，然后接下来就只出队这么多结点。
这样就可以实现分层了。
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false || root == NULL) {
            // 记录当前队列大小，也就是当前层结点数
            vector<int> currentLevel;
            int currentLevelSize = q.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // 将当前结点插入子数组
                currentLevel.push_back(node->val);

                // 将当前结点的子结点插入队列
                // 注意插入前判断是否为空
                if (node->left) {
                    q.emplace(node->left);
                }
                if(node->right) {
                    q.emplace(node->right);
                }
            }
            res.push_back(currentLevel);
        }

        return res;
    }
};
