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
    int fib(int n) {
        vector<long long> f(3, 0);
        f[1] = 1; f[2] = 1;

        if (n < 3) {
            return f[n];
        }

        for (int i = 3; i <= n; ++i) {
            f[0] = f[1];
            f[1] = f[2];
            f[2] = f[0] + f[1];
            cout << f[2] << endl;
        }
        return f[2];
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
    vector<vector<int>> test(1, vector<int>(1, -5));

    long long res = sol.fib(45);
    cout << res;

    return 0;
}