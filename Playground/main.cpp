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
    vector<int> exchange(vector<int>& nums) {
        int front = 0, back = nums.size() - 1;
        while (front < back) {
            if (nums[front] % 2 == 1) {
                ++front;
                continue;
            }
            if (nums[back] % 2 == 0) {
                --back;
                continue;
            }
            if (nums[front] % 2 == 0 && nums[back] % 2 == 1) {
                swap(nums[front], nums[back]);
            }
        }

        return nums;
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
    vector<int> nums2{1,2,3,4};
    
    vector<int> res = sol.exchange(nums2);
    cout << '1';

    return 0;
}