/*
0142. Linked List Cycle II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。

思路：双指针法
参考：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
设置快慢两个指针，快的每次走两步，慢的每次走一步。解题分为两个部分：
1）确定链表是不是有环。如果有环，两个指针必然相遇。
首先显然，快走的步数为f = 2s
其次，快和慢都先走了非环部分a，然后在环部分b多绕了n圈和慢指针相遇，因此有f = s + nb。
由这两个式子可以得到：f = 2nb, s = nb，也就是快慢指针分别走了2n，n个环的周长。

2）确定环的入口
相遇的位置不一定是环的入口，所以需要找环的入口。
假设非环部分长度为a，环部分长为b，那么一个指针如果停留在环入口处，需要走a + nb步。
但是现在慢指针只走了nb步，所以还需要走a步，才能走到入口。
因此，再设一个指针从head开始，一直走，直到和慢指针重合，就可以确定那是入口位置。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        // 首先确定是否有环
        while (true) {
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        // 如果有环，确定入口
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
