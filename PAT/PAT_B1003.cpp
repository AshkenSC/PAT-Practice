// PAT B1003

/*
1. 关键是理解条件3，其含义是：假设P之前有a个A，
则PT之间每多一个A，则T后面就要多a个A。
本质是：P前A数量*PT之间A数量==T后A数量

2. 使用map存储出现过的字母及其出现次数。

3. 注意字符串各项细节要求：
有且仅有PAT三种字母；
PT有且仅有一个；
PT之间不可无A字母；
满足题设条件3
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int pPos = 0, tPos = 0;
    string s;

    for(int i = 0; i < num; i++)
    {
        cin >> s;
        //map charCount统计各字母出现字数
        map<char, int> charCount;
        // 遍历字符串，统计字符数量与位置
        for(int j = 0; j < s.length(); j++)
        {
            charCount[s[j]]++;
            // 记录P和T 位置
            if(s[j] == 'P')
                pPos = j;
            if(s[j] == 'T')
                tPos = j;
        }
        // 检查字符串是否符合要求
        if(charCount['P']==1 && charCount['T']==1 &&
                charCount['A'] != 0 &&
                charCount.size() == 3 &&
                tPos - pPos != 1 &&
                // P左*PT之间 == T右？
                pPos*(tPos - pPos - 1) == s.length() - tPos - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}