// PAT B1083

/*
������������洢�˿������֣���������ȫ����Ҫ
ֻ��һ�������diffCnt[]¼ÿ����ֵ���ֵĴ��� 
ֻ���ڶ���ÿ������ʱ�����ȥ��ǰ����˳��ţ�ȡ����ֵdiff 
Ȼ��diffCnt�����Ӧ��diff����λ+1
����diffCntĩβ��ʼ�������¼ֵ���ڵ���2�ߣ������¼���� 
*/ 

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num, cardBackNum;
    cin >> num;
    vector<int> diffCnt(num);

    for(int i = 1; i <= num; i++) {
        cin >> cardBackNum;
        diffCnt[abs(i - cardBackNum)]++;
    }
    for(int i = num - 1; i >= 0; i--) {
        if(diffCnt[i] >= 2) {
            cout << i << " " << diffCnt[i] << endl;
        }
    }

    return 0;
}


