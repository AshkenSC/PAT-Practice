// PAT B1094

/*
问题：怎样判断素数
解答：让除数从2到sqrt(num)，如果有数可以整除被除数，则不是素数

主函数中的for循环，判断条件必须为<=，否则会有两个测试点不通过
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
