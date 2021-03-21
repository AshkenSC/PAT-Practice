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
    vector<vector<int>> res;

    void addSequence(int start, int end) {
        vector<int> newSeq;

        for (int i = start + 1; i <= end; ++i) {
            newSeq.push_back(i);
        }

        res.push_back(newSeq);
    }

public:
    vector<vector<int>> findContinuousSequence(int target) {
        int deductSum = 0, addSum = 1;
        int i = 0, j = 1;

        while (i < j && j < target) {
            if (addSum - deductSum == target) {
                addSequence(i, j);
                ++j;
                addSum = addSum + j;
            }
            else if (addSum - deductSum > target) {
                ++i;
                deductSum = deductSum + i;
            }
            else if (addSum - deductSum < target) {
                ++j;
                addSum = addSum + j;
            }
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
    vector<vector<int>> n = sol.findContinuousSequence(9);
    cout << 'a';

    return 0;
}