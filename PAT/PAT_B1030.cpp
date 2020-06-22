// PAT B1030

/*
思想非常简单，但满分不超时不容易想到（对我而言）：
首先对输入数据升序排列。然后遍历所有数据设为min，计算min*p
在内层循环，如果数不超过min*p就继续，每次循环更新maxLen，直到超过阈值。

注意！！外层循环遍历min时，不要挨个遍历，否则将有测试点超时或报错！
直接从当前i加maxLen到新的i。因为从i到i+maxLen 都是数列a[i]~a[i+maxLen]的子集 
注定不可能得到比母集更大的maxLen！ 

*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(long long a, long long b);

int main() {
    int num;
    long long p;
    long long maxLen = 0;

    // data input
    scanf("%d %lld", &num, &p);
    vector<long long> input(num);
    for(int i = 0; i < num; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end(), cmp);

    // calculate
    for(int i = 0; i < num; i++) {
        for(int j = i + maxLen; j < num; j++) {
            long long threshold = p * input[i];
            if(input[j] <= threshold) {
                if(j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                }
            }
            else {
                break;
            }
        }
    }

    // print result
    cout << maxLen;

    return 0;
}

bool cmp(long long a, long long b) {
    return a < b;
}

