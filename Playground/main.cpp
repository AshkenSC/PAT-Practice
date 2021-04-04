#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <set>
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
    set<char> validChar{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-'};
public:
    int strToInt(string str) {
        long long res = 0;
        int i = 0;
        bool isNegative = false;

        // 字符串为空
        if (str.size() == 0) {
            return res;
        }
        // 丢弃空字符
        for (; str[i] == ' '; ++i);

        // 第一个非空格字符不是一个有效整数字符
        // 字符串仅包含空白字符时
        // 则你的函数不需要进行转换
        if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
            || i == str.size()) {
            return res;
        }

        // 如果第一个有效字符是符号，处理符号
        if (str[i] == '-') {
            isNegative = true;
            ++i;
        }
        else if (str[i] == '+') {
            isNegative = false;
            ++i;
        }
        
        // 处理数字部分
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + str[i] - '0';
            if (!isNegative && res > INT_MAX) {
                return INT_MAX;
            }
            else if (isNegative && -res < INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }
        // 给绝对值加符号
        res = isNegative ? -res : res;
        return (int)res;
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
    
    int res = sol.strToInt("1");
    cout << res;

    return 0;
}