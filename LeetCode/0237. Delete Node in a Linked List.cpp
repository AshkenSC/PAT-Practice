/*
0237. Delete Node in a Linked List

本题目的难点在于如何获取给定结点前面的结点。结论是，直接交换当前结点和下一个结点的value，然后删除下一个结点
*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        swap(node->val, node->next->val);
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete(temp);
    }
};

int main() {

    Solution sol;
    ListNode
    bool res = sol.uniqueOccurrences(A);
    cout << res;

    return 0;
}