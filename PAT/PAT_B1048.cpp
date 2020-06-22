#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/*
Test input

1234567 368782971
*/

int main()
{
    char numA[110], numB[110];
    char tempA[110], tempB[110];
    char out[110];
    int lenA, lenB, len;

    scanf("%s %s", &numA, &numB);
    lenA = strlen(numA);
    lenB = strlen(numB);

    // Reverse A and B
    len = lenA;
    for(int i = 0; len >= 0; i++)
    {
        tempA[i] = numA[len - 1];
        len--;
    }
    len = lenB;
    for(int i = 0; len >= 0; i++)
    {
        tempB[i] = numB[len - 1];
        len--;
    }

    // If string A is longer than string B,
    // add 0s on left of string B for complement
    if(lenA > lenB)
    {
        for(int i = lenB; i < lenA; i++)
        {
            tempB[i] = '0';
        }
    }

    // Calculate classified number
    for(int i = 0; i < lenA; i++)
    {
        if((i+1) % 2 == 0)
        // If currently an even position
        {
            out[i] = tempB[i] - tempA[i];
            if(out[i] < 0)
            {
                out[i] += 10;
            }
        }
        else
        // If currently an odd position
        {
            out[i] = (tempA[i]-'0' + tempB[i]-'0') % 13;
            if(out[i] > 9)
            {
                if(out[i] == 10)
                {
                    out[i] = 'J';
                }
                else if(out[i] == 11)
                {
                    out[i] = 'Q';
                }
                else if(out[i] == 12)
                {
                    out[i] = 'K';
                }
                continue;
            }
        }
        // Transfer int to char
        out[i] = out[i] + '0';
    }
    // If string B is longer than string A
    if(lenB > lenA)
    {
        for(int i = lenA; i < lenB; i++)
        {
            out[i] = tempB[i];
        }
    }

    // Print result
    for(int i = max(lenA, lenB) - 1; i >= 0; i--)
    {
        printf("%c", out[i]);
    }

    return 0;
}

