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
    vector<int> singleNumbers(vector<int>& nums) {
        // 首先，将nums中的所有数进行亦或。
        // 最终得到的ret，出现两次的数亦或得全0，两个单独的数互不相同的比特位在ret中为1
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }

        // 找到ret中为1的最低位，也就是两个单独的数最低的不同比特位
        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }

        // 利用上一步找到的最低不同比特位div，进行分组
        // 和div做亦或操作，等于1，放到a组，等于0，放到b组
        // 出现两次的数由于在该位相同，会被分到同一组，从而消去
        // 出现一次的两个数由于在该位不同，所以必定会分到不同组
        int a = 0, b = 0;
        for (int n : nums) {
            if (div & n)
                a ^= n;
            else
                b ^= n;
        }

        return vector<int>{a, b};
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
    vector<int> test({0,1,2,3,4,5,6});
    int n = sol.missingNumber(test);
    cout << n;

    return 0;
}