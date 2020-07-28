/*
0107. Binary Tree Level Order Traversal II

给定一个二叉树，自底向上、从左到右地返回结点的值。
从样例来看，应该返回一个二维数组，每个子数组是每层返回的结果。
思路：可以先自顶向下、从右到左地层序遍历该树，然后将数组里的元素逆序排列（但要保持二维数组的结构）。

问题：
1）层序遍历
使用队列进行。
queue.enque(root)
while queue is not empty:
    current = queue.deque()
    result.add(current)
    queue.enque(current.right)
    queue.enque(current.left)

 但这只是基本的层序遍历算法，不能记录层次，无法满足本题要求。

 2）如何将不同层次的结点放在不同子数组里
 使用哨兵结点，其值用于记录层数。
 若没有轮到哨兵出队，则将结点放进子数组里。
 若轮到它出队，说明达到了当前层次终点。将当前子数组放进最终数组里，并将哨兵立刻重新入队。

 改进以后的算法：
 result = list()
 sublist = list()
 queue.enque(root)
 queue.enque(sentinal)
 while not (queue.size()==1 and queue.deque() == sentinal):
    current = queue.deque()
    if current is sentinal:
        result.append(sublist)
        sublist = list()
        queue.enque(sentinal)
    else:
        sublist.append(current)
        queue.enque(current.right)
        queue.enque(current.left)
最后还要将result数组逆序。

注意：
1）清空数组：使用clear()
subArray.clear();

2）反转vector：使用<algorithm>里的reverse()
reverse(subArray.begin(),subArray.end())

3）记得处理空结点输入情形。
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> subArray;
        queue<TreeNode> q;
        // 哨兵设了一个古怪的值，作为标志。如果可以修改结点结构，我会增加一个布尔值isSentinal用于判断。
        TreeNode sentinal = TreeNode(-114514);
        TreeNode currentNode;

        // 处理空结点输入
        if (root == nullptr) {
            return result;
        }

        // 初始化队列，插入根结点和哨兵
        q.push(*root);
        q.push(sentinal);

        while (!(q.size() == 1 && q.front().val == -114514)) {
            currentNode = q.front();
            q.pop();
            // 如果当前结点是哨兵
            if (currentNode.val == -114514) {
                result.push_back(subArray);
                subArray.clear();      // 清空子数组
                q.push(sentinal);
            }
            // 如果当前结点非哨兵
            else {
                subArray.push_back(currentNode.val);
                if (currentNode.left != nullptr) {
                    q.push(*currentNode.left);
                }
                if (currentNode.right != nullptr) {
                    q.push(*currentNode.right);
                }
            }
        }
        // 将最后的子数组放入总数组
        if (subArray.size() > 0) {
            result.push_back(subArray);
        }

        // 反转总数组
        reverse(result.begin(), result.end());

        return result;
    }
};

