// PAT B1009

/*
使用stack（栈）存储单词。由于stack具有“先进后出”的特性，因此最先输入的单词将被最后输出，故适用于本题；
本题中使用到的stack的基本操作：
stack<数据类型> stackName;	创建一个名为stackName的指定类型的栈；
stack.push(a);		将元素a入栈；
stack.pop();		弹出（删除）栈顶元素；
stack.top();		返回栈顶元素；
stack.empty();		返回一个布尔值，栈空为true，非空为false；
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> words;
    string input;
    while(cin >> input) {
        words.push(input);
    }
    while(!words.empty())
    {
        cout << words.top();
        words.pop();
        if(!words.empty()) {
        // 控制末尾空格
            cout << " ";
        }
    }
    return 0;
}


