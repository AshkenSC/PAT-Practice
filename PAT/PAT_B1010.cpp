// PAT B1010

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int coef, exp;
    int flag = 1;   // 1. final space output control; 2. 0 polynomial check
    while(scanf("%d %d", &coef, &exp) != EOF)
    {
        if(exp > 0)
        {
            if(flag == 1)
            {
               printf("%d %d", coef * exp, exp - 1);
               flag = 0;
            }
            else
            {
                printf(" %d %d", coef * exp, exp - 1);
            }
        }
    }
    if(flag == 1)
    // if the program run to this place and the flag is still 1
    // its derivative is a 0 polynomial
    {
        printf("0 0");
    }

    return 0;
}





