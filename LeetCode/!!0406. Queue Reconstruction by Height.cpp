/*
0406. Queue Reconstruction by Height

假设你有一个打乱的列表，代表一队排队的人。每个人由一对整数(h, k)表示，其中h是人的身高，k是排在他前面的且身高大于等于h的人数。写一个函数重构这个队列，使得重构后的队列符合上述描述。注意：总人数小于1100.

思路：贪心算法。本解法用到了一些生疏技术：如容器list，以及如何将list转为vector。
参考：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-8xing-dai-m/

将身高先降序排列，在此基础上，相同身高按k升序排列。
循环地从头读取排序后的数组，根据每个元素的k插入list链表。

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

插入过程：
先排序：70 71 61 50 52 44
再插入list：
70
70 71
70 61 71
50 70 61 71
50 70 52 61 71
50 70 52 61 44 71
*/

class Solution {
private:
    bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] <= b[1];
        else
            return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序，按身高降序排列，相同身高再按k升序排列
        sort(people.begin(), people.end(), 
        [](const vector<int>& lhs, const vector<int>& rhs) 
            {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];}
        );
        // 插入链表
        list<vector<int>> temp;
        int len = people.size();
        for (int i = 0; i < len; i++) {
            auto pointer = temp.begin();        // 先初始化指针，让它指向链表头节点
            advance(pointer, people[i][1]);     // 再让指针向前移动k位，到达插入位置
            temp.insert(pointer, people[i]);    // 插入链表
        }
        // 将list转换为vector再返回
        return vector<vector<int>>(temp.begin(), temp.end());
    }
};