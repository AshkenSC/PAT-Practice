/*
0002. Add Two Numbers

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

思路：参考解答中解法2
https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-gpe3dbjds1/

当数的长度不一样时，不补全长度，而是直接逐位计算和，并考虑进位。
*/


// 二刷
// 采用上面的思想去计算。在计算长度不同的部分时，代码繁琐了。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *p = head;
        int carry = 0;
        
        // 计算公共部分
        while (l1 && l2) {
            int current = l1->val + l2->val + carry;
            if (current >= 10) {
                current -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            p->next = new ListNode(current);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // 计算非公共部分
        // 这一部分l1和l2代码冗余
        if (l1) {
            while (l1) {
                int current = l1->val + carry;
                if (current >= 10) {
                    current -= 10;
                    carry = 1;
                }
                else {
                    carry = 0;
                }

                p->next = new ListNode(current);
                p = p->next;
                l1 = l1->next;
            }
            if (carry == 1) {
                p->next = new ListNode(1);
            }
        }
        else {
            while (l2) {
                int current = l2->val + carry;
                if (current >= 10) {
                    current -= 10;
                    carry = 1;
                }
                else {
                    carry = 0;
                }

                p->next = new ListNode(current);
                p = p->next;
                l2 = l2->next;
            }
            if (carry == 1) {
                p->next = new ListNode(1);
            }
        }
    
        return head->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);  // 结果头指针
        ListNode *p = head;                 // 工作指针
        int sum = 0;                        // 记录和
        int carry = 0;                     // 记录进位
        while (l1 != nullptr || l2 != nullptr) {
            // 重置sum
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            // 进位
            sum += carry;
            sum >= 10 ? carry = 1 : carry = 0;
            // 结果链表中新增结点
            p->next = new ListNode(sum % 10);
            // 移动工作指针
            p = p->next;
        }
        // 处理最后的进位
        if (carry == 1)
            p->next = new ListNode(1);
        // 返回结果
        return head->next;
    }
};