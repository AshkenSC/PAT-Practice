// PAT B1009

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 100;

int main() {
    char input[MAXN];

    // input string
    fgets(input, MAXN, stdin);
    // print words except the first one
    for(int i = strlen(input)-1; i >= 0; i--) {
        int j;
        if(input[i] == ' ') {
            // meet space, print a word reversely
            j = i + 1;
            while(input[j] != '\0') {
                if(input[j] == '\n') {
                    j++;
                    continue;
                }
                else {
                    printf("%c", input[j++]);
                }
            }
            // print a space
            printf(" ");
            // replace current space with \0
            input[i] = '\0';
        }
    }
    // print the last(originally the first) word
    for(int i = 0; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }

    return 0;
}





