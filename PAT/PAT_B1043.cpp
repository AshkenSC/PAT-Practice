// PAT B1043

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const char OUTPUT[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main() {

    // define and initialize variables
    char inputString[MAXN];
    int inputCharCount[150] = {0};
    int outputCharCount[6];
    bool isFinished = false;

    // data input
    fgets(inputString, MAXN, stdin);
    for(int i = 0; i < strlen(inputString); i++) {
        inputCharCount[inputString[i]]++;
    }
    outputCharCount[0] = inputCharCount['P'];
    outputCharCount[1] = inputCharCount['A'];
    outputCharCount[2] = inputCharCount['T'];
    outputCharCount[3] = inputCharCount['e'];
    outputCharCount[4] = inputCharCount['s'];
    outputCharCount[5] = inputCharCount['t'];

    // print result
    while(isFinished == false) {
        isFinished = true;
        for(int i = 0; i < 6; i++) {
            if(outputCharCount[i] > 0) {
                isFinished = false;
                outputCharCount[i]--;
                printf("%c", OUTPUT[i]);
            }
        }
    }


    return 0;
}
