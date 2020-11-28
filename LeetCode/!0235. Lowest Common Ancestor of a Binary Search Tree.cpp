/*
0235. Lowest Common Ancestor of a Binary Search Tree

找BST的最近公共祖先

思路：不难！但没想到！！
如果两个节点值都小于根节点，说明他们都在根节点的左子树上，我们往左子树上找
如果两个节点值都大于根节点，说明他们都在根节点的右子树上，我们往右子树上找
如果一个节点值大于根节点，一个节点值小于根节点，说明他们他们一个在根节点的左子树上一个在根节点的右子树上，那么根节点就是他们的最近公共祖先节点。

作者：sdwwld
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-3c/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 此时p，q分别在root下左右两侧子树里，则root就是他俩的公共祖先
        if ((root->val - p->val) * (root->val - q->val) <= 0) {
            return root;
        }
        // p，q分别位于同一侧，则需要继续向下找
        else {
            return lowestCommonAncestor(root->val > p->val ? root->left : root->right, p, q);
        }
    }
};