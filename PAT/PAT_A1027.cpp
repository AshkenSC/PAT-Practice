#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    int rgb10[3];
    stack<int> rgb13[3];

    // Scan decimal numbers and store them in stacks
    scanf("%d %d %d", &rgb10[0], &rgb10[1], &rgb10[2]);
    for(int i=0, rgbTemp; i<3; i++)
    {
        rgbTemp = rgb10[i];
        do
        {
            rgb13[i].push(rgbTemp % 13);
            rgbTemp = rgbTemp / 13;
        }while(rgbTemp >= 13);
        if(rgb10[i] > 13)
        {
            rgb13[i].push(rgbTemp);
        }
    }

    // Print numbers using radix 13
    printf("#");
    int tempChar;
    for(int i=0; i<3; i++)
    {
        // Print 0 for 1-digit colors
        if(rgb13[i].size() == 1)
        {
            printf("0");
        }
        // Print color codes
        while(rgb13[i].empty() == false)
        {
            tempChar = rgb13[i].top();
            rgb13[i].pop();
            if(tempChar >= 10)
            {
                if(tempChar == 10)
                {
                    printf("A");
                }
                else if(tempChar == 11)
                {
                    printf("B");
                }
                else if(tempChar == 12)
                {
                    printf("C");
                }
            }
            else
            {
                printf("%d", tempChar);
            }
        }
    }

    return 0;
}
