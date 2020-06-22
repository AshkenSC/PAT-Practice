// PAT B1057

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int GetSerial(char c);

int main() {

    char input[100010];
    long long sum = 0;
    long long zeroNum = 0, oneNum = 0;

    fgets(input, 100010, stdin);
    for(int i = 0; i < strlen(input); i++) {
        sum += GetSerial(input[i]);
    }
    while(sum != 0) {
        if(sum % 2 == 1) {
            oneNum++;
        }
        else {
            zeroNum++;
        }
        sum /= 2;
    }

    printf("%lld %lld", zeroNum, oneNum);

    return 0;
}

int GetSerial(char c) {
    int serial;
    if(c >= 'a' && c <= 'z') {
        serial = c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        serial = c - 'A' + 1;
    }
    else {
        serial = 0;
    }
    return serial;
}

