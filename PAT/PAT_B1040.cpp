// PAT B1040

/*
��AΪpivot����ÿ��A���P�������������ұ�T�����������ǵ�ǰA����ɵ�PAT����

���ȱ�����¼T������ 
�ٱ�������PAT����������P����P����++������T��T����==��
����A�����������㵱ǰA����ɵ�PAT������

���ǵ� �� 1000000007 ȡ������ 
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int pCount = 0, tCount = 0;
    long long patCount = 0;

    getline(cin, input);
    int len = input.size();
    for(int i = 0; i < len; i++) {
        if(input[i] == 'T') {
            tCount++;
        }
    }
    for(int i = 0; i < len; i++) {
        if(input[i] == 'P') {
            pCount++;
        }
        if(input[i] == 'T') {
            tCount--;
        }
        if(input[i] == 'A') {
            patCount += pCount * tCount;
        }
    }

    patCount %= 1000000007;
    cout << patCount;
    return 0;
}

