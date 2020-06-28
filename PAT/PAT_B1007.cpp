// PAT B1007

/*
从5到n，判断相差2的两个数是否同时为素数。若满足，则素数对个数+1。

判断素数时，若严格按照定义判断，则会超时。判断m是否为素数，只需从2判断到根号m，看是否有因数即可。
因为若m是合数，则若将其分为两个因数的积，其中一个若小于等于根号m，则另一个必然大于等于根号m。
因此，若在小于等于根号m的范围内发现m的因数，则必然存在一个对应的、大于等于根号m的因数，和它乘积为m。
所以只需判断根号m范围内是否有因数，就可确定m是否为素数。
*/

#include <iostream>
#include <cmath>
using namespace std;

// 判断素数
bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    int primeCnt = 0;
    cin >> n;
    for (int i = 5; i <= n; i++)
        if (isPrime(i-2) && isPrime(i))
            primeCnt++;
    cout << primeCnt;
    return 0;
}