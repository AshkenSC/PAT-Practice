/*
0129. Sum Root to Leaf Numbers

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。

思路：DFS同时记录每个路径的数字。然后计算和。
*/

#include <cstring>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> numbers;

    void traverse(TreeNode* node, string num_str) {
        // 到达了叶子结点
        if (node->left == nullptr && node->right == nullptr) {
            int num = stoi(num_str + to_string(node->val));
            numbers.push_back(num);
            return;
        }
        // DFS
        else {
            if (node->left != nullptr)
                traverse(node->left, num_str + to_string(node->val));
            if (node->right != nullptr)
                traverse(node->right, num_str + to_string(node->val));
        }
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;

        traverse(root, "");
        int sum = 0;
        for (auto num : numbers) {
            sum += num;
        }
        return sum;
    }
};
