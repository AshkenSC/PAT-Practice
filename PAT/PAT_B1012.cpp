// PAT B1012

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
    // A[0] and flag[0] will not be used
    // store A1 to A5
    float A[6] = {0};
    // flags to mark if a kind of number has appeared
    bool flag[6] = {0};
    // controlling coefficient in A2
    int a2Coef = 1;
    // counting numbers added in A4
    int a4Count = 0;

    // input and process
    int num, input;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &input);
        if(input % 10 == 0)
        // A1
        {
            flag[1] = true;
            A[1] = A[1] + input;
        }
        else if(input % 5 == 1)
        // A2
        {
            flag[2] = true;
            A[2] = A[2] + a2Coef * input;
            a2Coef = 0 - a2Coef;
        }
        else if(input % 5 == 2)
        // A3
        {
            flag[3] = true;
            A[3] = A[3] + 1;
        }
        else if(input % 5 == 3)
        // A4
        // A[4] does not store the final output
        // just the sum of qualified numbers
        {
            flag[4] = true;
            A[4] = A[4] + input;
            a4Count++;
        }
        else if(input % 5 == 4)
        // A5
        {
            flag[5] = true;
            if(input > A[5])
            {
                A[5] = input;
            }
        }
    }

    // output
    for(int i = 1; i <= 5; i++)
    {
        if(flag[i] == false)
        {
            printf("N");
        }
        else
        {
            if(i == 4)
            // A4 is not an integer
            {
                printf("%.1f", A[i] / a4Count);
            }
            else
            // print integer
            {
                printf("%d", (int)A[i]);
            }
        }
        // print space
        if(i != 5)
        {
            printf(" ");
        }
    }

    return 0;
}





