// PAT B1017

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    char num[1010];
    char result[1010];
    int quotient, remainder;
    int div;

    scanf("%s %d", num, &div);
    for(int i = 0; i < strlen(num); i++) {
        if(i == 0) {
            quotient = (num[i] - '0') / div;
            remainder = (num[i] - '0') % div;
            result[i] = quotient + '0';
        }
        else {
            quotient = (remainder * 10 + num[i] - '0') / div;
            remainder = (remainder * 10 + num[i] - '0') % div;
            result[i] = quotient + '0';
        }
    }
    result[strlen(num)] = '\0';

    if(result[0] == '0' && strlen(num) > 1) {
        printf("%s %d", result + 1, remainder);
    }
    else {
        printf("%s %d", result, remainder);
    }

    return 0;
}






