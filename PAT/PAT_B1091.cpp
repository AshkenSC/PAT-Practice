// PAT B1091

/*
    自守数 automorphic number
    （1）根据M确定大循环次数；
    （2）每次大循环中，执行小循环，n从1自增到9，检测是否自守数；
    （3）根据输入K的位数不同（1位数2位数3位数），分别检测自守数情况。
*/

#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long lineNum, testee, product;

    cin >> lineNum;
    while(lineNum > 0) {
        cin >> testee;
        int n;
        for(n = 1; n < 10; n++) {
            product = n * testee * testee;
            if(testee < 10) {
            // input number is one-digit
                if(product % 10 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
            else if(testee >= 10 && testee <= 99) {
            // input number is two-digit
                if(product % 100 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
            else {
            // input number is three-digit
                if(product % 1000 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
        }

        if(n < 10) {
        // current number is automorphic
            cout << n << " " << product << endl;
        }
        else {
        // current number is not automorphic
            cout << "No" << endl;
        }

        lineNum--;
    }

    return 0;
}