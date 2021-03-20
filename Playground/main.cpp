#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <stack>
#include <string>
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

/*
dp[i][j] （i，j）格能拿到最高价值的礼物
dp[0][0] = a[0][0]
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j]
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tempMax = 1, tempMin = 1;
        int res = nums[0];

        for (auto num : nums) {
            if (num < 0) {
                swap(tempMax, tempMin);
            }
            tempMax = max(num, tempMax * num);
            tempMin = min(num, tempMin * num);
            res = max(res, tempMax);
        }

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
    // [[1,3,1],[1,5,1],[4,2,1]]
    Solution sol;
    vector<vector<int>> input({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    vector<int> test({3,4,0,-1,3});
    int n = sol.maxProduct(test);
    cout << n;

    return 0;
}