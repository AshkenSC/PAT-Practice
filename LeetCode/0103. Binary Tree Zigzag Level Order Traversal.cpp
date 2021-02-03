/*
0103. Binary Tree Zigzag Level Order Traversal

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

思路：
参考https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/jiao-ti-shi-yong-zhan-jian-dan-shi-xian-ju-chi-xin/
普通层序遍历进入队列，这个尝试进入栈。
但是，如果只是设计一个栈，那么每次出站一个元素后，直接插入其孩子节点，就会干扰到出站元素后面的兄弟节点正常出站。
所以使用两个栈交替出入。

思路2：
整体方法类似102题层序遍历。但如果是偶数层，将其逆序即可。
*/

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        stack<TreeNode*> stack1, stack2;

        if (root == nullptr)
            return result;
        else
            stack1.emplace(root);

        while (stack1.empty() == false || stack2.empty() == false) {
            vector<int> subList;
            if (stack1.empty() == false) {
                while (stack1.empty() == false) {
                    // 出栈
                    TreeNode *currentNode = stack1.top();
                    stack1.pop();

                    // 插入结果子链表
                    subList.push_back(currentNode->val);

                    // stack2插入当前结点的孩子
                    if (currentNode->left != nullptr) {
                        stack2.push(currentNode->left);
                    }
                    if (currentNode->right != nullptr) {
                        stack2.push(currentNode->right);
                    }
                }
                // 将子链表插入总链表
                result.push_back(subList);
            }
            else {
                while (stack2.empty() == false) {
                    // 出栈
                    TreeNode *currentNode = stack2.top();
                    stack2.pop();

                    // 插入结果子链表
                    subList.push_back(currentNode->val);

                    // stack1插入当前结点的孩子
                    if (currentNode->right != nullptr) {
                        stack1.push(currentNode->right);
                    }
                    if (currentNode->left != nullptr) {
                        stack1.push(currentNode->left);
                    }
                }
                // 将子链表插入总链表
                result.push_back(subList);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL) {
            return res;
        }

        int level = 1;  // 用于记录层数，判定节点存入次序
        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false && root != NULL) {
            vector<int> subList;
            int currentLevelSize = q.size();

            for (int i = 0; i < currentLevelSize; ++i) {
                auto node = q.front();
                q.pop();
                subList.push_back(node->val);

                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            
            // 如果是偶数层，将其逆序
            if (level % 2 == 0) {
                reverse(subList.begin(), subList.end());
            }
            ++level; 
            res.push_back(subList);
        }

        return res;
    }
};
