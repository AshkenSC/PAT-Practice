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
private:
    int res;

    int partition(vector<int>& a, int low, int high) {
        int i = low, j = high + 1, pivot = a[low];

        while (true) {
            while (a[++i] > pivot) {
                if (i >= high) break;
            }
            while (a[--j] < pivot) {
                if (j <= low) break;
            }

            if (i >= j) break;
        
            swap(a[i], a[j]);
        }
        swap(a[low], a[j]);

        return j;
    }

    void partitionArray(vector<int>& a, int low, int high, int k) {
        int m = partition(a, low, high);

        if (m == k - 1) {
            res = a[m];
            return;
        }
        else if (k - 1 < m) {
            partitionArray(a, low, m - 1, k);
        }
        else if (k - 1 > m) {
            partitionArray(a, m + 1, high, k);
        }
    }


public:
    int findKthLargest(vector<int>& nums, int k) {
        partitionArray(nums, 0, nums.size() - 1, k);
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
    vector<int> test({1});
    int n = sol.findKthLargest(test, 1);
    cout << n;

    return 0;
}