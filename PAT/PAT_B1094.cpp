// PAT B1094

/*
���⣺�����ж�����
����ó�����2��sqrt(num)���������������������������������

�������е�forѭ�����ж���������Ϊ<=����������������Ե㲻ͨ��
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool isPrime(int a) {
    for(int i = 2; i < sqrt(a); i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int l, k;
    int nNum;
    string nStr, sub;

    scanf("%d %d\n", &l, &k);
    getline(cin, nStr);
    for(int i = 0; i <= l - k; i++) {
        sub = nStr.substr(i, k);
        if(isPrime(atoi(sub.c_str()))) {
            cout << sub;
            return 0;
        }
    }

    cout << "404";
    return 0;
}
