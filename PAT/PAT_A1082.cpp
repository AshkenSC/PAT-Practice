#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char digits[10][5] = {
    "ling","yi", "er",
    "san", "si", "wu",
    "liu","qi", "ba",
    "jiu"};
char scale[3][10] = {
    "Qian", "Bai", "Shi"};

int main()
{
    char input[20];
    int priorPos = -1;  // prior non-zero position
    scanf("%s", &input);

    // If the number is negative or zero
    if(input[0] == '-')
    {
        // Print "Fu"
        printf("Fu ");
        // Remove '-' in the string for convenience
        for(int i = 1; i <= strlen(input); i++)
        {
            input[i-1] = input[i];
        }
    }
    if(input[0] == '0')
    {
        printf("ling");
        return 0;
    }

    // number format (add zeros)
    int originalLen = strlen(input);
    for(int i = strlen(input); i >= 0; i--)
    {
        input[i + 9 - originalLen] = input[i];
    }
    for(int i = 0; i < 9 - originalLen; i++)
    {
        input[i] = '0';
    }

    //Test format
//    for(int i = 0; i < 9; i++)
//    {
//        printf("%c", input[i]);
//    }
//    printf("\n");
    // Test format

    // Process Yi
    if(input[0] != '0')
    {
        printf("%s Yi", digits[input[0]-'0']);
        priorPos = 0;
    }
    // Process the rest
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            if(input[i*4+j] != '0')
            {
                if(priorPos == -1)
                // It is the first non-zero position
                {
                    printf("%s", digits[input[i*4+j] - '0']);
                    if(j != 4)
                    {
                        printf(" %s", scale[j-1]);
                    }
                    priorPos = i * 4 + j;
                }
                else
                // If it is not the first non-zero position
                {
                    if((i*4+j - priorPos > 1) &&
                       (i*4+j != 5))
                    // If last neighbor position is zero
                    {
                        printf(" ling");
                    }
                    if(i*4+j == 5 && priorPos == 0)
                    // special case: 1, 0000, 8000
                    {
                        printf(" ling");
                    }

                    printf(" %s", digits[input[i*4+j] - '0']);
                    if(j != 4)
                    {
                        printf(" %s", scale[j-1]);
                    }
                    priorPos = i * 4 + j;
                }
            }
        }
        // Print "Wan" if it is the first time of outer loop
        if(i == 0 && (priorPos >= 1 && priorPos <= 4))
        {
            printf(" Wan");
        }
    }

	return 0;
}

