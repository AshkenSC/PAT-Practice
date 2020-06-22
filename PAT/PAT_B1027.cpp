// PAT B1027

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int num, n;
    char sym;

    // data input
    scanf("%d %c", &num, &sym);
    // confirm size of the hourglass
    for(n = 1; (2*n*n - 1) <= num; n++);
    n--;

    // print the hourglass
    // print top
    for(int i = 2*n-1; i >= 1; i -= 2) {
        // print left space
        for(int j = 0; j < (2*n-1 - i) / 2; j++) {
            printf(" ");
        }
        // print the hourglass
        for(int j = 0; j < i; j++) {
            printf("%c", sym);
        }
        printf("\n");
    }
    // print bottom
    for(int i = 3; i <= 2*n-1; i += 2) {
        // print left space
        for(int j = 0; j < (2*n-1 - i) / 2; j++) {
            printf(" ");
        }
        // print the hourglass
        for(int j = 0; j < i; j++) {
            printf("%c", sym);
        }
        printf("\n");
    }

    // print the number of symbols left
    printf("%d", num - (2*n*n - 1));

    return 0;
}





