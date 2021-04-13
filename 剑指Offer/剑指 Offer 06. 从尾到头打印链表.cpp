/*
剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

思路1：先逆置，再输出。

思路2：借助辅助栈，先进后出进行逆置。
*/

// 思路2
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> res;

        while (head != nullptr) {
            s.emplace(head->val);
            head = head->next;
        }

        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

// 思路1
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (head == nullptr) {
            return res;
        }

        ListNode *pre = nullptr, *p = head, *next = head->next;
        while (next != nullptr) {
            p->next = pre;
            pre = p;
            p = next;
            next = next->next;
        }
        p->next = pre;

        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }

        return res;
    }
};
