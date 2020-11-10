/*
0328. Odd Even Linked List

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

思路：一边遍历一边修改原结点的指针。
注意！最后是偶数子链表结尾，一定要将偶数子链表的最后一个结点的next改为null。

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode *odd = head;
        ListNode *pOdd = odd;
        ListNode *even = head->next;
        ListNode *pEven = even;
        
        ListNode *p = even->next;
        for (int i = 3; p != nullptr; i++) {
            if (i % 2 == 1) {
                pOdd->next = p;
                pOdd = p;
            }
            else {
                pEven->next = p;
                pEven = p;
            }
            p = p->next;
        }
        pEven->next = nullptr;  // 注意！对新结尾，要修改其结尾为null
        pOdd->next = even;

        return head;
    }
};