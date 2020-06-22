// PAT B1087

/*
用集合set存储所有 不同的算式结果，insert时将会自动过滤重复结果
最后输出集合大小即可 
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int num, ans;
    set<int> answerSet;

    cin >> num;
    for(int i = 1; i <= num; i++) {
        ans = i / 2 + i / 3 + i / 5;
        answerSet.insert(ans);
    }
    cout << answerSet.size();

    return 0;
}


