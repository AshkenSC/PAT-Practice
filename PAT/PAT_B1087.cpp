// PAT B1087

/*
�ü���set�洢���� ��ͬ����ʽ�����insertʱ�����Զ������ظ����
���������ϴ�С���� 
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


