// PAT B1075

/*
用数组作静态链表,data[add], next[add]分别表示add地址存储数据及下地址
输入数据暂存后，遍历之。根据数据类别(<0, 0toK, >k)将其分别push_back进三个子链表中 
按照顺序输出三个子链表

注意：输出结果时，在打印next地址时，尽量不要在循环内使用i+1等 
之前使用类似方式输出，造成段错误，无法排查，最终更换输出方式全通过 

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

