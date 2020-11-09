/*
0086. Partition List

思路：设置两个子链表，small, large，分别为小于x和大于等于x的元素构成的子链表的表头。
再设置一个smallTail，用于指向small的尾部，方便将large连接在small后面。
遍历原链表，只要小于x，就接在small后面。大于等于x，接在large后面。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return head;

        // small, large都是dummy头结点
        // i和j都是对应的工作指针
        ListNode *small = new ListNode(0);
        ListNode *i = small;
        ListNode *large = new ListNode(0);
        ListNode *j = large;

        ListNode *p = head;
        while (p != nullptr) {
            if (p->val < x) {
                i->next = new ListNode(p->val);
                i = i->next;
            }
            else {
                j->next = new ListNode(p->val);
                j = j->next;
            }
            p = p->next;
        }
        // 将小数链表尾和大数链表头相连
        // large是dummy头，真正的开头是large->next
        i->next = large->next;

        return small->next;
    }
};