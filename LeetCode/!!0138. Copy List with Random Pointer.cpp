/*
0138. Copy List with Random Pointer

思路：参考了高赞评论，由java转写来
先复制链表的val，下一步再复制next和random指向
将存储了val的克隆结点暂存在hash表里，与原身结点一一映射
这样虽然克隆结点之间暂时没有连接关系，但是原身之间是有对应关系的
可以通过原身映射找到对应克隆结点，再通过原身next，找到下一个克隆结点，在这过程中复制next和random值
*/

#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        Node *node = head;
        // 用map存储链表结点之间的映射
        map<Node *, Node *> match;
        // 先复制链表的val，下一步再复制next和random指向
        // 将存储了val的克隆结点暂存在hash表里，与原身结点一一映射
        // 这样虽然克隆结点之间暂时没有连接关系，但是原身之间是有对应关系的
        // 可以通过原身映射找到对应克隆结点，再通过原身next，找到下一个克隆结点，在这过程中复制next和random值
        while (node) {
            Node *clone = new Node(node->val);
            match[node] = clone;
            node = node->next;
        }
        node = head;
        // 复制next和random指向
        while (node) {
            match[node]->next = match[node->next];
            match[node]->random = match[node->random];
            node = node->next;
        }
        return match[head];
    }
};