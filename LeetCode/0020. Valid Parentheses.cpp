/*
0020. Valid Parentheses

给定一个字符串，判断该字符串里包含的所有括号是否都是有效的。有两个要求：
1）一个左括号必须搭配一个同类的右括号；
2）左右括号的位置必须正确。
此外空字符串也被当作正确字符串。

思路1：使用map记录所有左括号'(',  '{',  '[' 的个数。每次读取字符串的一个字符。
每次读取右括号时，先看看对应的左括号计数是否为0。如果为0，则直接返回不合法。如果不为0，则对应左括号的计数-1。
最后结束时，必须保证所有左括号的计数为0，否则也不合法。

这个思路存在一个问题：
形如"([)]"的字符串，是不合法的，括号对之间交叉了。

思路2：采用栈记录所有左括号，遇到左括号就入栈。如果遇到右括号就看当前它和栈顶左括号是否对应。如果不对应则返回false。


map插入数据
1）mapStudent.insert(pair<int, string>(1, "student_one"));
2）或采用数组方式leftCount['('] = 0;

map的遍历
1)
map<string,int>::iterator iter;//定义一个迭代指针iter
for(iter=M.begin(); iter!=M.end(); iter++)
    cout<<iter->first <<"->"<<iter->second<<endl;

2)
for (auto member : leftCount) {
    if (member.second != 0) {
        return false;
    }
}
*/

// 思路1（错误
class Solution1 {
public:
    bool isValid(string s) {
        // 空串是合法串
        if (s == "")
            return true;

        // 初始化map
        map<char, int> leftCount;
        leftCount['('] = 0;
        leftCount['['] = 0;
        leftCount['{'] = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                leftCount[s[i]] += 1;
            }
            else {
                if (s[i] == ')') {
                    if (leftCount['('] == 0)
                        return false;
                    else {
                        leftCount['('] -= 1;
                    }
                }
                else if (s[i] == ']') {
                    if (leftCount['['] == 0)
                        return false;
                    else {
                        leftCount['['] -= 1;
                    }
                }
                else {
                    if (leftCount['{'] == 0)
                        return false;
                    else {
                        leftCount['{'] -= 1;
                    }
                }
            }
        }
        // 遍历结束，如果还剩余左括号，则也非法
        for (auto member : leftCount) {
            if (member.second != 0) {
                return false;
            }
        }
        return true;
    }
};

// 思路2
class Solution {
public:
    bool isValid(string s) {
        if (s == "") {
            return true;
        }

        stack<char> leftStack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                leftStack.push(s[i]);
            }
            else if (s[i] == ')') {
                if (leftStack.empty() || leftStack.top() != '(')
                    return false;
                else
                    leftStack.pop();
            }
            else if (s[i] == ']') {
                if (leftStack.empty() || leftStack.top() != '[')
                    return false;
                else
                    leftStack.pop();
            }
            else if (s[i] == '}') {
                if (leftStack.empty() || leftStack.top() != '{')
                    return false;
                else
                    leftStack.pop();
            }
        }

        // 最后栈应当为空，才合法
        return leftStack.empty();
    }
};