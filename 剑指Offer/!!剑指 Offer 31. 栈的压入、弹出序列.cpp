/*
剑指 Offer 31. 栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

思路：
参考Krahets解答。不知是不是因为睡眠不足，对思路还没有透彻理解。
核心思想是模拟出入栈过程。
我现在能理解的是：遍历出栈顺序表。每进入一个新元素，就对照出栈顺序表。
如果当前栈顶和出栈顺序表当前遍历到的元素相等，就说明该把栈顶弹出来了。

参考：
https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/mian-shi-ti-31-zhan-de-ya-ru-dan-chu-xu-lie-mo-n-2/
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;

        for (auto num : pushed) {
            s.emplace(num);
            while (s.empty() == false && s.top() == popped[i]) {
                s.pop();
                ++i;
            }
        }

        return s.empty();
    }
};
