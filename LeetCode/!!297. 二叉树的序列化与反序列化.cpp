/*
297. 二叉树的序列化与反序列化

请设计一个算法来实现二叉树的序列化与反序列化。

思路：
使用层序遍历。
注意点：
1）序列化不要用string，要用ostringstream，否则会超时
2）反序列化用istringstream，这样可以方便地处理空格，分割字符串
3）字符串转为整数，使用stoi函数

参考：
https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/zi-jie-ti-ku-297-kun-nan-er-cha-shu-de-xu-lie-hua-/
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 不能使用string，否则会超时！
        // 必须使用ostringstream
        ostringstream out;
        if (root == nullptr) {
            return "";
        }
        queue<TreeNode*> q;
        q.emplace(root);
        while (q.empty() == false) {
            TreeNode* current = q.front();
            q.pop();
            if (current) {
                out << current->val << " ";
                q.emplace(current->left);
                q.emplace(current->right);
            }
            else {
                out << "null ";
            }
        }

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    // 如何用空格分割字符串？使用istringstream，就像cin会自动用空格换行分割一样
    // 如何将字符串转为整数？使用stoi
        if (data == "") {
            return nullptr;
        }
        istringstream input(data);
        string info;
        vector<TreeNode*> res;

        // 将字符串转存为节点数组
        while (input >> info) {
            if (info == "null") {
                res.push_back(nullptr);
            }
            else {
                res.push_back(new TreeNode(stoi(info)));
            }
        }
        
        // 由节点数组构造树
        int pos = 1;    // 用于指向子树节点
        for (int i = 0; pos < res.size(); ++i) {
            if (!res[i]) {
                continue;
            }
            res[i]->left = res[pos++];  // 此时pos指向左子树，++后指向右子树
            if (pos < res.size()) {
                res[i]->right = res[pos++]; // 此时pos指向右子树，++后指向下一个节点左子树
            }
        }

        return res[0];
    }
};
