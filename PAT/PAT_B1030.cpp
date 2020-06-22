// PAT B1030

/*
˼��ǳ��򵥣������ֲ���ʱ�������뵽�����Ҷ��ԣ���
���ȶ����������������С�Ȼ���������������Ϊmin������min*p
���ڲ�ѭ���������������min*p�ͼ�����ÿ��ѭ������maxLen��ֱ��������ֵ��

ע�⣡�����ѭ������minʱ����Ҫ���������������в��Ե㳬ʱ�򱨴�
ֱ�Ӵӵ�ǰi��maxLen���µ�i����Ϊ��i��i+maxLen ��������a[i]~a[i+maxLen]���Ӽ� 
ע�������ܵõ���ĸ�������maxLen�� 

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

