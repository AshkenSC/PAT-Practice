// PAT B1044

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const char martianLow[13][5] = {"tret", "jan", "feb", "mar",
                     "apr", "may", "jun", "jly",
                     "aug", "sep", "oct", "nov", "dec"};

const char martianHigh[13][5] = {"000", "tam", "hel", "maa",
                         "huh", "tou", "kes", "hei",
                         "elo", "syy", "lok", "mer", "jou"};

struct Data {
    char number[10];
    int language;
    // language = 0 stands for Martian
    // language = 1 stands for Human
} data[100];

void HumanToMartian(Data a);
void MartianToHuman(Data a);

int main() {

    // data input
    int num;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++) {
        fgets(data[i].number, 10, stdin);
        // identify language type
        if(data[i].number[0] >= '0' && data[i].number[0] <= '9') {
            data[i].language = 1;
        }
        else {
            data[i].language = 0;
        }
    }

    // process and print result
    for(int i = 0; i < num; i++) {
        if(data[i].language == 0) {
            MartianToHuman(data[i]);
        }
        else {
            HumanToMartian(data[i]);
        }
            cout << endl;
    }

    return 0;
}

void HumanToMartian(Data a) {
    int value = 0;
    int lowDigit, highDigit;
    // from string to int
    for(int i = 0; a.number[i] >= '0' && a.number[i] <= '9'; i++) {
        value = value * 10;
        value = value + a.number[i] - '0';
    }

    // translate to Martian
    if(value <= 12) {
        printf("%s", martianLow[value]);
    }
    else {
        highDigit = value / 13;
        printf("%s", martianHigh[highDigit]);
        lowDigit = value % 13;
        if(lowDigit != 0) {
            printf(" %s", martianLow[lowDigit]);
        }
    }
}

void MartianToHuman(Data a) {
    int i;
    int value = 0;
    if(strlen(a.number) < 5) {
    // the number is <= 12, or the number is n*times of 13
        a.number[strlen(a.number) - 1] = '\0';
        for(i = 0; i < 13; i++) {
        // the number is <= 12
            if(strcmp(a.number, martianLow[i]) == 0) {
                value = i;
            }
        }
        if(i == 13) {
        // the number is n*times of 13
            a.number[3] = '\0'; // get rid of the \n
            for(i = 1; i < 13; i++) {
               if(strcmp(a.number, martianHigh[i]) == 0) {
                    value = value + 13 * i;
               }
            }
        }
    }
    else {
    // the number is >= 13 and is not n*times of 13
        // insert \0 to separate high and low digits
        a.number[3] = '\0';
        a.number[7] = '\0';

        for(i = 1; i < 13; i++) {
        // print the high digit
           if(strcmp(a.number, martianHigh[i]) == 0) {
                value = value + 13 * i;
           }
        }
        for(i = 0; i < 13; i++) {
        // print the low digit
            if(strcmp(a.number + 4, martianLow[i]) == 0) {
                value = value + i;
            }
        }
    }

    printf("%d", value);
}

