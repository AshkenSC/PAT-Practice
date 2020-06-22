// PAT B1014

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 65;
const char days[7][5] = {"MON", "TUE", "WED",
                         "THU", "FRI", "SAT", "SUN" };

int main() {
    char inputStr[4][MAXN];

    // string input
    for(int i = 0; i < 4; i++) {
        scanf("%s", &inputStr[i]);
    }

    // extract the first common pair of capital letters in string 1 & 2
    int i;
    for(i = 0; inputStr[0][i] != '\0'; i++) {
        if(inputStr[0][i] >= 'A' && inputStr[0][i] <= 'G') {
            if(inputStr[0][i] == inputStr[1][i]) {
                break;
            }
        }
    }
    // print day of the date
    printf("%s ", days[inputStr[0][i] - 'A']);

    // find the second pair of common capital letters in string 1 & 2
    for(i = i + 1; inputStr[0][i] != '\0'; i++) {
        if(inputStr[0][i] >= 'A' && inputStr[0][i] <= 'N' ||
           inputStr[0][i] >= '0' && inputStr[0][i] <= '9') {
            if(inputStr[0][i] == inputStr[1][i]) {
                break;
            }
        }
    }
    // print hour of the date
    if(inputStr[0][i] >= '0' && inputStr[0][i] <= '9') {
        printf("%02d:", inputStr[0][i] - '0');
    }
    else {
        printf("%d:", inputStr[0][i] - 'A' + 10);
    }

    // find the first common lower-case letters from string 3 & 4
    for(i = 0; inputStr[2][i] != '\0'; i++) {
        if(inputStr[2][i] >= 'a' && inputStr[2][i] <= 'z' ||
           inputStr[2][i] >= 'A' && inputStr[2][i] <= 'Z') {
            if(inputStr[2][i] == inputStr[3][i]) {
                break;
            }
        }
    }
    // print minute of the date
    printf("%02d", i);

    return 0;
}





