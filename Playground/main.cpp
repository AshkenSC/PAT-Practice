#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <stack>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        
        string temp;
        for (char c : s) {
            // 如果是空格字符，且缓存字符串非空，将缓存单词存入栈
            if (c == ' ') {
                if (temp.size() > 0) {
                    words.push(temp);
                    temp = "";
                }
                else
                    continue;
            }
            // 非空字符，则存入缓存单词字符串后面
            else {
                temp.push_back(c);
            }
        }
        // 将最后一个单词入栈
        if (temp.size() > 0)
            words.push(temp);

        string res;
        while (words.size() > 1) {
            res += words.top() + " ";
            words.pop();
        }
        res += words.top();
        words.pop();

        return res;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    Solution sol;
    vector<int> nums1{4,0,0,0,0,0};
    vector<int> nums2{1,2,3,5,6};

    string res = sol.reverseWords(" hello world ");
    cout << res;

    return 0;
}