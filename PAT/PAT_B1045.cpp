// PAT B1045

/*
��ֹ��ʱ�ĺ����жϹ���1) ����ȷ�����λ����; 2) �������������

��һ�������˿��ŵ����ʣ�����һ�˺�pivotһ��������ȷλ���ϡ�
�ڶ���������ж��Ҳ࣬�����˱Ƚϴ��������һ�û�ܴ��������������ȷ�ԡ�

ע�⣺����pivotΪ0��������������0�⣬����Ҫ���һ���ջ��У� 
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long long> a(num), b(num);
    vector<int> pivots;
    for(int i = 0; i < num; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.begin() + num);
    long long maxNum = -1;
    for(int i = 0; i < num; i++) {
        if(a[i] == b[i] && a[i] > maxNum) {
        // KEY! You only have to ensure that a[i] > max on the left
        // no need to judge if a[i] < min on the right
            pivots.push_back(a[i]);
        }
        if(a[i] > maxNum) {
            maxNum = a[i];
        }
    }

    sort(pivots.begin(), pivots.begin() + pivots.size());
    cout << pivots.size() << endl;
    for(int i = 0; i < pivots.size(); i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << pivots[i];
    }
    if(pivots.size() == 0) {
    // You have to print an EMPTY line when there is no pivot
        printf("\n");
    }

    return 0;
}

