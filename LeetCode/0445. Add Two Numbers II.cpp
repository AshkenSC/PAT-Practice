/*
0445. Add Two Numbers II

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

思路：将数字压入栈中，然后逐个位运算。


*/

#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 将链表中数字存入栈中，翻转顺序
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        // 设置计算所需的变量
        ListNode *answer = nullptr;
        int carry = 0;
        // 依次出栈按位运算
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();
            if (! s2.empty())
                s2.pop();
            int currentSum = a + b + carry;
            int currentNum = currentSum % 10;
            carry = currentSum / 10;
            // 新建结点，插入结果链表
            // 头插法，每次插完将当前结点设为头结点
            auto currentNode = new ListNode(currentNum);
            currentNode->next = answer;
            answer = currentNode;
        }

        return answer;
    }
};