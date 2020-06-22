// PAT B1075

/*
����������̬����,data[add], next[add]�ֱ��ʾadd��ַ�洢���ݼ��µ�ַ
���������ݴ�󣬱���֮�������������(<0, 0toK, >k)����ֱ�push_back�������������� 
����˳���������������

ע�⣺������ʱ���ڴ�ӡnext��ַʱ��������Ҫ��ѭ����ʹ��i+1�� 
֮ǰʹ�����Ʒ�ʽ�������ɶδ����޷��Ų飬���ո��������ʽȫͨ�� 

*/ 

#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long firstAdd, nodeNum, k, tempAdd;
    long data[100000], next[100000];
    cin >> firstAdd >> nodeNum >> k;
    for(long i = 0; i < nodeNum; i++) {
        cin >> tempAdd;
        cin >> data[tempAdd] >> next[tempAdd];
    }

    vector<long> sorted[3];
    for(long i = firstAdd; i != -1; i = next[i]) {
        if(data[i] < 0) {
            sorted[0].push_back(i);
        }
        else if(data[i] > k) {
            sorted[2].push_back(i);
        }
        else {
            sorted[1].push_back(i);
        }
    }

    int flag = 0;
    for(long i = 0; i < 3; i++) {
        for(long j = 0; j < sorted[i].size(); j++) {
           if(flag == 0) {
                printf("%05d %d ", sorted[i][j], data[sorted[i][j]]);
                flag = 1;
            }
            else {
                printf("%05d\n%05d %d ", sorted[i][j], sorted[i][j], data[sorted[i][j]]);
            }
        }
    }
    printf("-1");

    return 0;
}

