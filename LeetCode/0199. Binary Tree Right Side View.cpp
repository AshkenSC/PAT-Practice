/*
0199. Binary Tree Right Side View

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

思路：层序遍历。只保留每层最后一个元素。
那么如何区分不同层？考虑使用两个队列轮流存储。
*/

#include <cstring>
#include <vector>
#include <string>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        queue<TreeNode *> q1, q2;
        q1.emplace(root);
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                TreeNode *currentNode = q1.front();
                q1.pop();
                // 是当前层最后一个结点，保存
                if (q1.empty())
                    res.push_back(currentNode->val);
                // 将其孩子放入另一个队列
                if (currentNode->left != nullptr)
                    q2.emplace(currentNode->left);
                if (currentNode->right != nullptr)
                    q2.emplace(currentNode->right);
            }
            while (!q2.empty()) {
                TreeNode *currentNode = q2.front();
                q2.pop();
                // 是当前层最后一个结点，保存
                if (q2.empty())
                    res.push_back(currentNode->val);
                // 将其孩子放入另一个队列
                if (currentNode->left != nullptr)
                    q1.emplace(currentNode->left);
                if (currentNode->right != nullptr)
                    q1.emplace(currentNode->right);
            }
        }

        return res;
    }
};
