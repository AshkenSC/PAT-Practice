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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        while (q.empty() == false) {
            // 记录当前队列大小，也就是当前层结点数
            int currentLevelSize = q.size();
            vector<int> subList;
            for (int i = 0; i < currentLevelSize; i++) {
                auto currentNode = q.front();
                q.pop();
                // 将当前结点插入子数组
                subList.push_back(currentNode->val);
                // 将当前结点的子结点插入队列
                // 注意插入前判断是否为空
                if (currentNode->left)
                    q.push(currentNode->left);
                if (currentNode->right)
                    q.push(currentNode->right);
            }
            // 将子数组插入结果数组里
            result.push_back(subList);
        }

        return result;
    }
};