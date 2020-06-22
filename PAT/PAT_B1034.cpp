
// PAT B1034

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

long a1, b1, a2, b2;
long int3, a3, b3;
bool isLargerThan1;  // mark whether the result is >1
bool isNegative;     // mark whether the result is <0
bool isInf = false; // mark whether the result is infinite

void Euclid(long* a, long* b);
void FormatOut(long a, long b);
void Add(long a1, long b1, long a2, long b2);
void Sub(long a1, long b1, long a2, long b2);
void Mul(long a1, long b1, long a2, long b2);
void Div(long a1, long b1, long a2, long b2);

int main() {

    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    Add(a1, b1, a2, b2);    cout << endl;
    Sub(a1, b1, a2, b2);    cout << endl;
    Mul(a1, b1, a2, b2);    cout << endl;
    Div(a1, b1, a2, b2);

    return 0;
}

void Euclid(long* a, long* b) {
    long c;
    long a0 = abs(*a);
    long b0 = abs(*b);
    int aSymbol = *a / abs(*a);

    if(a0 == 0 || b0 == 0) {
        return;
    }
    if(a0 < b0) {
        swap(a0, b0);
    }

    while(1) {
        c = a0 % b0;
        if(c == 0) {
            *a = aSymbol * (*a) / b0;
            *b = (*b) / b0;
            break;
        }
        else {
            if(a0 < b0) {
                b0 = c;
            }
            else {
                a0 = b0;
                b0 = c;
            }
        }
    }
}

void FormatOut(long a, long b) {
    if(isInf == true) {
    // if the result is infinite
        printf("Inf");
        return;
    }
    if(a == 0) {
    // if a/b is 0
        printf("0");
        return;
    }
    if(a < 0) {
    // if a/b is negative
        isNegative = true;
        printf("(-");
    }
    Euclid(&a, &b);
    if(abs(a) >= abs(b)){
    // print integer part
        printf("%ld", abs(a/b));
        if(a % b != 0) {
            printf(" ");
        }
    }
    if(b != 1) {
    // if a/b is not a pure integer
        printf("%ld/%ld", abs(a%b), abs(b));
    }
    if(isNegative == true) {
    // if a is negative, print right parenthesis
        printf(")");
    }
    isNegative = false;     // reset the flag
}

void Add(long a1, long b1, long a2, long b2) {
    // calculate result, store it in a3/b3
    a3 = a1 * b2 + a2 * b1;
    b3 = b1 * b2;

    // format output operands
    FormatOut(a1, b1);
    printf(" + ");
    FormatOut(a2, b2);
    printf(" = ");
    FormatOut(a3, b3);
}

void Sub(long a1, long b1, long a2, long b2) {
    // calculate result, store it in a3/b3
    a3 = a1 * b2 - a2 * b1;
    b3 = b1 * b2;

    // format output operands
    FormatOut(a1, b1);
    printf(" - ");
    FormatOut(a2, b2);
    printf(" = ");
    FormatOut(a3, b3);
}

void Mul(long a1, long b1, long a2, long b2) {
    // calculate result, store it in a3/b3
    a3 = a1 * a2;
    b3 = b1 * b2;

    // format output operands
    FormatOut(a1, b1);
    printf(" * ");
    FormatOut(a2, b2);
    printf(" = ");
    FormatOut(a3, b3);
}

void Div(long a1, long b1, long a2, long b2) {
    // format output operands
    FormatOut(a1, b1);
    printf(" / ");
    FormatOut(a2, b2);
    printf(" = ");

    // if the result is infinite
    if(a2 == 0) {
        isInf = true;
    }
    // calculate result, store it in a3/b3
    // calculate absolute value first
    a3 = abs(a1 * b2);
    b3 = abs(b1 * a2);
    if(a1 * a2 < 0) {
    // then deal with the symbol
        a3 = 0 - a3;
    }

    FormatOut(a3, b3);
}



