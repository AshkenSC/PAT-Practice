// PAT B1074

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {

    int numSys[21], lenSys;
    for(int i = 0; i < 20; i++) numSys[i] = 0; // initialize numSys
    int num1[21] = {0}, len1;
    int num2[21] = {0}, len2;
    int sum[21] = {0};
    char tempStr[25];

    // data input
    fgets(tempStr, 25, stdin);
    lenSys = strlen(tempStr) - 1;
    for(int i = 20, j = lenSys - 1; j >= 0; j--) {
        numSys[i--] = tempStr[j] - '0';
    }
    fgets(tempStr, 25, stdin);
    len1 = strlen(tempStr) - 1;
    for(int i = 20, j = len1 - 1; j >= 0; j--) {
        num1[i--] = tempStr[j] - '0';
    }
    fgets(tempStr, 25, stdin);
    len2 = strlen(tempStr) - 1;
    for(int i = 20, j = len2 - 1; j >= 0; j--) {
        num2[i--] = tempStr[j] - '0';
    }

    // calculate
    int digitSum;
    int incFlag = 0;
    for(int i = 20; i >= 0; i--) {
        digitSum = num1[i] + num2[i] + incFlag;
        incFlag = 0;
        if(numSys[i] != 0) {
        // current digit is decimal
            if(digitSum >= numSys[i]) {
                digitSum -= numSys[i];
                incFlag = 1;
            }
        }
        else {
        // current digit is not decimal
            if(digitSum >= 10) {
                digitSum -= 10;
                incFlag = 1;
            }
        }
        sum[i] = digitSum;
    }

    // print result
    int i;
    for(i = 0; sum[i] == 0 && i < 20; i++);   // skip zeros at the beginning
    for(; i < 21; i++) {
        printf("%d", sum[i]);
    }

    return 0;
}

