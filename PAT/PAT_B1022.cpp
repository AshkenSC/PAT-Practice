// PAT B1022

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    long num1, num2; int sys;
    int digits[999]; int pos;
    scanf("%ld %ld %d", &num1, &num2, &sys);

    // short-divide to get digits
    num1 = num1 + num2;
    if(num1 == 0) {
        // when the sum is 0
        printf("0");
        return 0;
    }
    for(pos = 0; num1 > 0; pos++) {
        digits[pos] = num1 % sys;
        num1 = num1 / sys;
    }

    // print result from digits[] reversely
    for(pos= pos - 1; pos >= 0; pos--) {
        printf("%d", digits[pos]);
    }

    return 0;
}





