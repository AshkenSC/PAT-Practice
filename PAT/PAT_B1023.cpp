// PAT B1023

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    // input[] stores input data
    // out[] stores output digits
    int input[10], out[50];
    // sum stores total inputber of the digits
    int sum = 0, digitNum;
    int i, j;

    // data input, calculate sum
    for(i = 0; i <= 9; i++) {
        scanf("%d", &input[i]);
        sum = sum + input[i];
    }
    // copy sum to digitNum, to control result output at last
    digitNum = sum;

    // generate output inputber
    for(i = 0; sum > 0; i++) {
        if(i == 0) {
        // generate the first digit
        // the first digit cannot be 0
            for(j = 1; j <= 9; j++) {
                if(input[j] > 0) {
                    break;
                }
            }
            out[i] = j;
            input[j]--;
            sum--;
            continue;
        }
        for(j = 0; j <= 9; j++) {
            if(input[j] > 0) {
                break;
            }
        }
        out[i] = j;
        input[j]--;
        sum--;
        continue;
    }

    // print result
    for(int i = 0; i < digitNum; i++) {
        printf("%d", out[i]);
    }

    return 0;
}





