/*
0092. Reverse Linked List II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
1 ≤ m ≤ n ≤ 链表长度。

思路：参考https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/92-fan-zhuan-lian-biao-ii-by-da-tang-x/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 增加虚空头结点
        ListNode *dummyHead = new ListNode(0, head);
        // 将工作指针移动到m前一个位置
        ListNode *pre = dummyHead;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        // 遍历，逐个翻转链表
        // 通过修改指针，跳过del，来逐个“删除”del
        // 再将删除的del，逐个接到del后面
        // 最终实现反转
        ListNode *cur = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode *del = cur->next;
            cur->next = del->next;
            del->next = pre->next;
            pre->next = del;
        }
        // 返回头结点
        return dummyHead->next;
    }
};