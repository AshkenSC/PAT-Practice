/*
0061. Rotate List

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

思路：自己想的，和下面这个链接一致
https://leetcode-cn.com/problems/rotate-list/solution/kuai-man-zhi-zhen-xi-jie-yao-gao-hao-by-lilychao/

假设链表长度为n，那么向右移动k个位置实际上就是向右移动 k % n 个位置。
设置两个指针fast，slow，都放在头部。fast先走k % n步。然后fast和slow同时走，直到fast->next == null停下。
此时，slow->next是新头部。设newHead = slow->next，并将slow->next设为null，将fast->next设为head。完成“旋转”。
最后，返回newHead，即得到结果。

注意处理一些边界情形：空链表，移动0位，链表长度为1等。
*/

#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 处理一些空链表、移动0位、链表长度为1等情形
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // 遍历一次得到链表长度
        int n = 0;
        for (ListNode *p = head; p->next != nullptr; p = p->next)
            n++;
        // 计算实际旋转移动多长
        k = k % n;
        // 如果实际移动0位，直接返回
        if (k == 0)
            return head;
        // 设置双指针，找到链表新头
        ListNode *fast = head;
        ListNode *slow = head;
        // fast先走k步，然后fast和slow一起走
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 此时，slow->next是新头部。设newHead = slow->next，
        // 并将slow->next设为null，将fast->next设为head。完成“旋转”。
        // 最后，返回newHead，即得到结果
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};