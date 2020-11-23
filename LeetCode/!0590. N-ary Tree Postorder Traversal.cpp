/*
0590. N-ary Tree Postorder Traversal

给定一个 N 叉树，返回其节点值的后序遍历。

思路：
先序遍历，然后翻转。
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        
        if (root == nullptr)
            return res;

        stack<Node *> s;
        s.emplace(root);
        Node *pre = nullptr;
        while (s.empty() == false) {
            // 获取当前元素
            Node *node = s.top();
            s.pop();
            res.push_back(node->val);
            // 将当前元素的孩子入栈
            for (int i = 0; i < node->children.size(); i++) {
                s.emplace(node->children[i]);
            }
        }

        // 反转地球
        reverse(res.begin(), res.end());
        return res;
    }
};
