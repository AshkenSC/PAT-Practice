// PAT B1019

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(char a, char b);
bool cmpR(char a, char b);
void toArray(int num, int* numArray);
int toNum(int* numArray);

int main() {

    int input, inputR;
    int inputArray[4];
    bool sameDigits = true;

    // number input
    scanf("%d", &input);
    while(1) {
        // store digits into the array
        for(int i = 0; i < 4; i++) {
            inputArray[i] = input % 10;
            input = input / 10;

            // judge if 4 digits are identical
            if(i > 0 && inputArray[i] != inputArray[i - 1]) {
                sameDigits = false;
            }
        }

        // sort digits in descending order
        sort(inputArray, inputArray + 4, cmp);
        // transform back to descending-order number
        input = 0;
        for(int i = 0; i < 4; i++) {
            input += inputArray[i];
            if(i < 3) {
                input = input * 10;
            }
        }

        // if 4 digits are identical, print as follows and exit
        if(sameDigits == true) {
            printf("%d - %d = 0000", input, input);
            return 0;
        }

        // sort digits in ascending order
        sort(inputArray, inputArray + 4, cmpR);
        // transform back to ascending-order number
        inputR = 0;
        for(int i = 0; i < 4; i++) {
            inputR = inputR + inputArray[i];
            if(i < 3) {
                 inputR = inputR * 10;
            }
        }

        // print and calculate
        printf("%04d - ", input);
        printf("%04d", inputR);
        input = input - inputR;
        printf(" = %04d\n", input);

        // exit when the loop reaches 6174
        if(input == 6174) {
            break;
        }
    }

    return 0;
}

bool cmp(char a, char b) {
    return a > b;
}

bool cmpR(char a, char b) {
    return a < b;
}





