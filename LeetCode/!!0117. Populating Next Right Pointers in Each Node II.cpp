/*
0117. Populating Next Right Pointers in Each Node II

给定一个二叉树,填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

你只能使用常量级额外空间。

思路：层次遍历。参考官方解答2。
核心思想是在第x层给第x+1层建立next指针。
当一层的指针建立完成后，移动到x+1层，给x+2层建立指针。
依靠next指针，我们因此只需要常数空间。
*/

#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if (last != nullptr) {
            last->next = p;
        }
        if (nextStart == nullptr) {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node *start = root;
        while (start) {
            Node *last = nullptr;
            Node *nextStart = nullptr;
            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    handle(last, p->left, nextStart);
                }
                if (p->right) {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }

        return root;
    }
};
