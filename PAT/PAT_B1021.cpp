// PAT B1021

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int stat[10] = {0};
    char input[1010];

    // input and count
    scanf("%s", &input);
    for(int i = 0, temp = 0; input[i] != '\0'; i++) {
        temp = input[i] - '0';
        stat[temp]++;
    }

    // print result
    for(int i = 0; i < 10; i++) {
        if(stat[i] != 0) {
            printf("%d:%d\n", i, stat[i]);
        }
    }

    return 0;
}





