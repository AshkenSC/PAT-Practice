// PAT B1042

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct Data {
    char c;
    int freq;
} data[150];

bool cmp(Data a, Data b);

int main() {

    // define and initialize variables
    char inputString[MAXN];
    for(int i = 0; i < 150; i++) {
        data[i].c = i;
        data[i].freq = 0;
    }

    // data input
    fgets(inputString, MAXN, stdin);
    for(int i = 0; i < strlen(inputString); i++) {
        if(inputString[i] >= 'A' && inputString[i] <= 'Z') {
            data[inputString[i] + 'a' - 'A'].freq++;
        }
        else {
            data[inputString[i]].freq++;
        }
    }

    // sort input data
    sort(data + 'a', data + 'z' + 1, cmp);

    // print result
    printf("%c %d", data['a'].c, data['a'].freq);

    return 0;
}

bool cmp(Data a, Data b) {
    if(a.freq != b.freq) {
        return a.freq > b.freq;
    }
    else {
        return a.c < b.c;
    }
}



