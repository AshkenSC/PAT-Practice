/*
剑指 Offer 35. 复杂链表的复制

请实现 copyRandomList 函数，复制一个复杂链表。

思路：
参考高赞评论。
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

        // 复制节点值和next
        Node *p = head;
        while (p != nullptr) {
            Node *copy = new Node(p->val);
            copy->next = p->next;
            p->next = copy;
            p = p->next->next;
        }

        // 复制随机指针
        p = head;
        while (p != nullptr) {
            // 让p指向原身，则p->random也是原身，p->random->next就是原身的拷贝
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        // 链表一分为二
        Node *copyHead = head->next;
        p = head;
        Node *pCopy = head->next;
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
