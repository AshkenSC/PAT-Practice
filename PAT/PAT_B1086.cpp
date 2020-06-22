// PAT B1086

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long a, b, ans, digit;
    bool firstNonZero = 0;
    cin >> a >> b;
    ans = a * b;
    while(ans > 0) {
        digit = ans % 10;
        if(digit == 0 && firstNonZero == 0) {
            ans = ans / 10;
            continue;
        }
        else {
            firstNonZero = 1;
            cout << ans % 10;
            ans = ans / 10;
        }
    }

    return 0;
}


