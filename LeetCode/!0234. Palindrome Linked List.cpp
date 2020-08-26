/*
0234. Palindrome Linked List

给定一个单链表，确定它是否是回文链表。

思路：使用快慢指针同时遍历，慢指针一次走一步，快指针一次走两步。
慢指针边走边用另两个指针p和pre翻转链表。其中，p先走，pre后走（用于翻转时记录next）
这样，如果快指针走到头的时候，慢指针正好翻转到一半。
然后这时候慢指针和指针p分别指向前半和后半链表的开头，同时遍历二者，查看值是否相同。

注意：如果结点数量为奇数个，需要跳过中间节点。
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* p = head;
        ListNode* pre = nullptr;
        // 空链表算回文链表
        if (!head || !head->next)
            return true;
        // 这里不能只写while(fast)，一方面因为fast一次走2步，要保证fast.next.next不为空。
        // 另一方面，为了后面能用fast试探出链表总数是否为奇数个。
        while (fast && fast->next) {
            // 遍历
            p = slow;
            slow = slow->next;
            fast = fast->next->next;

            // 翻转
            p->next = pre;
            pre = p;
        }
        // 如果链表是奇数个结点，跳过中点
        if (fast)
            slow = slow->next;
        // 现在前半和后半链表分别以p和slow开头。遍历之
        while (slow && p) {
            if (slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};