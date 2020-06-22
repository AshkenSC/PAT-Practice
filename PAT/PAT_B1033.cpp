// PAT B1033

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100005;

int main() {
    char broken[128];
    char input[MAXN];
    bool isEmpty = true;        // check if the program print anything
    bool isBroken[128] = {0};   // set char appeared in the first line true

    fgets(broken, 128, stdin);
    fgets(input, MAXN, stdin);

    for(int i = 0; broken[i]; i++) {
        isBroken[(int)broken[i]] = true;
    }

    for(long i = 0; input[i]; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
        // deal with capital letters
            if(isBroken['+'] == true || isBroken[(int)input[i]] == true) {
                continue;
            }
            else {
                isEmpty = false;
                printf("%c", input[i]);
            }
        }
        else if(input[i] >= 'a' && input[i] <= 'z') {
        // deal with lower-case letters
            if(isBroken[input[i]-'a'+'A'] == false) {
                isEmpty = false;
                printf("%c", input[i]);
            }
        }
        else if(isBroken[(int)input[i]] == false){
            isEmpty = false;
            printf("%c", input[i]);
        }
    }

    if(isEmpty == true) {
    // if every key of characters in the input is broken
        printf("\n");
    }

    return 0;
}







