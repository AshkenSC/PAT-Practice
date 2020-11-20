/*
0589. N-ary Tree Preorder Traversal

给定一个 N 叉树，返回其节点值的前序遍历。

使用了迭代法，建立一个栈用来存储遍历的树。
*/

#include <vector>
#include <stack>
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> s;

        if (root == nullptr)
            return res;

        s.emplace(root);
        while (s.empty() == false) {
            // 获取栈顶元素，将其放入结果vector
            Node *currentNode = s.top();
            s.pop();
            res.push_back(currentNode->val);
            // 将当前元素的孩子入栈
            for (int i = currentNode->children.size() - 1; i >= 0; i--) {
                s.emplace(currentNode->children[i]);
            }
        }

        return res;
    }
};