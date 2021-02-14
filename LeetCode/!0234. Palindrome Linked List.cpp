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
        // 节点数为0或1，是回文
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 用2倍速指针和1倍速指针走过链表，直到2倍速指针到达链表末端
        ListNode *slow = head, *fast = head, *p = head, *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            // 遍历
            p = slow;
            fast = fast->next->next;
            slow = slow->next;

            // 慢速指针一边走一边反转链表
            p->next = pre;
            pre = p;
        }

        // 检查链表前后半是否回文
        if (fast) {
            slow = slow->next; // 奇数链情形, slow跳过中间点
        }
        while (p && slow) {
            if (p->val != slow->val) {
                return false;
            }
            p = p->next;
            slow = slow->next;
        }
       return true;
    }
};
