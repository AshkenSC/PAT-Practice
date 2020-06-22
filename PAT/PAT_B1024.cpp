// PAT B1024

/* test cases
+1.2345E-0
-2.7831434E-03
+1.7732837E+03
-1.22E+04


*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int decimal[9999], integer, expNum;
    int precision = 0;
    char temp, numSymbol, expSymbol;

    // data input
    // input symbol and integer part
    scanf("%c%d.", &numSymbol, &integer);
    // input decimal part
    for(int i = 0;; i++) {
        scanf("%c", &temp);
        if(temp == 'E') {
            break;
        }
        decimal[i] = (int)(temp - '0');
        precision++;
    }
    // input exponential part
    scanf("%c%d", &expSymbol, &expNum);

    // print result
    if(expNum == 0) {
    // (0) x^0 == 1
        printf("1.");
        for(int i = precision; i > 0; i--) {
            printf("0");
        }
        return 0;
    }
    if(numSymbol == '-') {
    // print negative symbol of the number
        printf("-");
    }
    if(expSymbol == '-') {
    // (1) exponential < 0
        printf("0.");
        for(int i = expNum - 1; i > 0; i--) {
        // print 0s between decimal point and effective digits
            printf("0");
        }
        // print digit of input integer part
        printf("%d", integer);
        for(int i = 0; i < precision; i++) {
        // print effective digits
            printf("%d", decimal[i]);
        }
        return 0;
    }
    else if(expSymbol == '+') {
    // (2) exponential > 0
        int i;
        printf("%d", integer);
        // (2-1) more digits, smaller exponential (1234.567)
        if(precision > expNum) {
            for(i = 0; i < expNum; i++) {
                printf("%d", decimal[i]);
            }
            printf(".");
            for(;i < precision; i++) {
                printf("%d", decimal[i]);
            }
            return 0;
        }
        // (2-2) less digits, larger exponential (123456700)
        else {
            for(i = 0; i < expNum; i++) {
                if(i < precision) {
                    printf("%d", decimal[i]);
                }
                else {
                    printf("0");
                }
            }
            return 0;
        }

    }
}





