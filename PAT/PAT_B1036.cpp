// PAT B1036

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int length, height;
    char c;

    scanf("%d %c", &length, &c);
    if(length % 2 == 0) {
        height = length / 2;
    }
    else {
        height = length / 2 + 1;
    }

    for(int i = 0; i < length; i++) {
        printf("%c", c);
    }
    cout << endl;
    for(int i = 0; i < height - 2; i++) {
        printf("%c", c);
        for(int j = 0; j < length - 2; j++) {
            printf(" ");
        }
        printf("%c\n", c);
    }
    for(int i = 0; i < length; i++) {
        printf("%c", c);
    }

    return 0;
}







