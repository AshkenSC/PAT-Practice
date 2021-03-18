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
    int trap(vector<int>& height) {
        // 考虑空列表情况
        if (height.empty()) {
            return 0;
        }

        int result = 0;
        // 用两个数组记录当前位置左边和右边最高值
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        // 求leftMax数组（第0个位置左边最高值为0）
        int tempMax = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = tempMax;
            tempMax = max(tempMax, height[i]);
        }
        // 求rightMax（最后一个位置右边最高值为0）
        tempMax = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = tempMax;
            tempMax = max(tempMax, height[i]);
        }

        // 遍历求结果
        for (int i = 1; i < n - 1; ++i) {
            int water = height[i] - min(leftMax[i], rightMax[i]);
            result += max(water, 0);
        }

        return result;
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
    vector<int> test({0,1,0,2,1,0,1,3,2,1,2,1});
    int n = sol.trap(test);
    cout << n;

    return 0;
}