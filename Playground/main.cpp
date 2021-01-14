#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> stat;
        for (auto& word : words) {
            ++stat[word];
        }
        
        typedef pair<int, string> pis;
        auto cmp = [](pis& a, pis& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        priority_queue<pis, vector<pis>, decltype(cmp)> pq;
        for (auto& cnt : stat) {
            pq.push(make_pair(cnt.second, cnt.first));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());

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
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> res = sol.topKFrequent(input, 2);
    for (auto num : res) {
        cout << num << " ";
    }

    return 0;
}