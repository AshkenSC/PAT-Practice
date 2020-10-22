/*
0430. Flatten a Multilevel Doubly Linked List

思路:参考
https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/zhong-gui-zhong-ju-fei-chang-xiang-xi-de-ti-jie-si/

遍历链表,遇到有子链表的就递归做展开,然后将父亲前半,子链表,父亲后半连接起来。
*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        auto cur = head;
        while (cur) {
            if (cur->child) {
                // 当前结点的下一个结点,也就是父亲链表后半部分的起点
                auto next = cur->next;
                // 递归展开子链表
                auto child = flatten(cur->child);
                // 找到子链表的最后一个结点
                auto last = cur->child;
                while (last->next) {
                    last = last->next;
                }
                // 将父链表前半段,子链表,父链表后半段相连
                cur->next = child;
                cur->child = nullptr;
                child->prev = cur;
                last->next = next;
                // 如果父链表后半段非空,设置其prev
                if (next) {
                    next->prev = last;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};