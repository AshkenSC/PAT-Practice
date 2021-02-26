/*
剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。

思路：参考高赞评论。
1）复制一个新的节点在原有节点之后，如 1 -> 2 -> 3 -> null 复制完就是 1 -> 1 -> 2 -> 2 -> 3 - > 3 -> null
2）从头开始遍历链表，通过 cur.next.random = cur.random.next 可以将复制节点的随机指针串起来，当然需要判断 cur.random 是否存在
3）将复制完的链表一分为二
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        // 完成链表节点复制
        Node *cur = head;
        while (cur != nullptr) {
            Node* copyNode = new Node(cur->val);
            copyNode->next = cur->next;
            cur->next = copyNode;
            cur = cur->next->next;
        }

        // 完成随机指针复制
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                // 注意这里，cur指向原身一个节点
                // 因此cur->random指向原身所指引的随机节点的拷贝
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // 分离链表
        Node *copyHead = head->next;
        Node *p = head, *pCopy = head->next;
        while (p != nullptr) {
            p->next = p->next->next;
            p = p->next;
            if (pCopy->next != nullptr) {
                pCopy->next = pCopy->next->next;
                pCopy = pCopy->next;
            } 
        }

        return copyHead;
    }
};
