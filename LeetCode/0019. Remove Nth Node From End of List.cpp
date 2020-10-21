/*
0019. Remove Nth Node From End of List

思路：双指针，一个指针fast先走n步，一个指针slow在起点待命。
然后两个指针同时移动，直到fast走到尾部。这时候slow指向的结点就是倒数第n个结点。
但是由于需要删除slow指向的结点，所以只能走到要删除的结点前一个结点位置。

注意！！考虑删除头节点情况。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        
        // fast先走n步
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // 注意！！可能删除的是第一个结点
        if (!fast)
            return head->next;
        // fast和slow同时走，一直到fast走到尾部
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 删除slow的下一个结点
        ListNode *deletedNode = slow->next;
        slow->next = slow->next->next;
        delete deletedNode;

        return head;
    }
};