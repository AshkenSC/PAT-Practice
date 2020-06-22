// PAT B1016

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    long long num1, num2, temp;
    int digit1, digit2;
    int count1 = 0, count2 = 0;
    long sum = 0, sum1 = 0, sum2 = 0;
    scanf("%lld %d %lld %d", &num1, &digit1, &num2, &digit2);

    for(temp = num1; temp > 0; temp = temp / 10) {
        int digitTemp;
        digitTemp = temp % 10;
        if(digitTemp == digit1) {
            count1++;
        }
    }
    for(temp = num2; temp > 0; temp = temp / 10) {
        int digitTemp;
        digitTemp = temp % 10;
        if(digitTemp == digit2) {
            count2++;
        }
    }

    while(count1 > 0) {
        sum1 = sum1 * 10;
        sum1 = sum1 + digit1;
        count1--;
    }
    while(count2 > 0) {
        sum2 = sum2 * 10;
        sum2 = sum2 + digit2;
        count2--;
    }
    sum = sum1 + sum2;

    printf("%ld", sum);

    return 0;
}





