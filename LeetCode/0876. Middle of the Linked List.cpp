/*
876. Middle of the Linked List

从头遍历一遍链表，一边将其内容放在一个数组中。然后利用数组随机访问的特点，立刻找到链表的中间位置
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodeList;
        ListNode* currentNodePtr = head;
        while (currentNodePtr != nullptr) {
            nodeList.push_back(currentNodePtr);
            currentNodePtr = currentNodePtr->next;
        }
        return nodeList[int(nodeList.size() / 2)];
    }
};

int main() {

    Solution sol;
    ListNode
    bool res = sol.uniqueOccurrences(A);
    cout << res;

    return 0;
}