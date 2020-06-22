// PAT B1083

/*
本来是用数组存储了卡背数字，但发现完全不需要
只需一个数组记diffCnt[]录每个差值出现的次数 
只需在读入每个数字时用其减去当前读入顺序号，取绝对值diff 
然后将diffCnt数组对应的diff计数位+1
最后从diffCnt末尾开始，数组记录值大于等于2者，输出记录即可 
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


