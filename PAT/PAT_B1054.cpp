// PAT B1054

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

   char input[100];
   int num, dotPos, legalNum = 0;
   float legalSum = 0;
   bool isLegal;

   scanf("%d", &num);
   for(int i = 0; i < num; i++) {
        scanf("%s", input);
        float value = 0.0;
        isLegal = true;
        dotPos = 0;

        // legality check: whether a number
        for(int j = 0; j < strlen(input); j++) {
            if(j == 0) {
            // check the first position
                if(!(input[j] == '-' || (input[j] >= '0' && input[j] <= '9'))) {
                    isLegal = false;
                    break;
                }
            }
            else if(input[j] == '.' || (input[j] > '0' && input[j] < '9')) {
            // check the 2~n position
                if(input[j] == '.' && dotPos != 0) {
                // redundant dots in 2~n position
                    isLegal = false;
                    break;
                }
                else if(input[j] == '.') {
                    dotPos = j;
                    continue;
                }
            }
        }

        // legality check: over-precision
        if(dotPos != 0 && strlen(input) - dotPos - 1 > 2) {
            isLegal = false;
        }

        // legality check: out of range
        for(int k = 0; k < strlen(input); k++) {
            if(input[k] < '0' || input[k] > '9') continue;
            value = value * 10.0;
            value = value + input[k] - '0';
        }
        if(input[0] == '-') {
                value = 0.0 - value;
        }
        if(dotPos != 0) {
            value = value / pow(10.0, strlen(input) - dotPos - 1);
        }
        if(fabs(value) > 1000) {
            isLegal = false;
        }

        // print illegal info or calculate
        if(isLegal == true) {
            legalNum++;
            legalSum += value;
        }
        else {
            printf("ERROR: %s is not a legal number\n", input);
        }
   }

   if(legalNum == 1) {
        printf("The average of 1 number is %.2f", legalSum);
   }
   else if(legalNum == 0) {
        printf("The average of 0 numbers is Undefined");
   }
   else {
        printf("The average of %d numbers is %.2f", legalNum, legalSum / (float)legalNum);
   }

}

