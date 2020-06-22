#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    char str[10010];
    int exp = 0;
    int posOfE = 0;

    scanf("%s", &str);
    // If it is a negative number, print "-"
    if(str[0] == '-')
    {
        printf("-");
    }
    // Find position of char E
    while(str[posOfE] != 'E')
    {
        posOfE++;
    }
    // Calculate exponent
    for(int i = posOfE + 2; str[i] != '\0'; i++)
    {
        exp = exp * 10 + str[i] - '0';
    }
    // If exponent < 0
    if(str[posOfE + 1] == '-')
    {
        printf("0.");
        // Print zeros before original base number
        for(int i = 0; i < exp - 1; i++)
        {
            printf("0");
        }
        // Print original base number
        // from str[1] to str[posOfE-1], ignoring "."
        for(int i = 1; i <= posOfE - 1; i++)
        {
            if(str[i] != '.')
            {
                printf("%c", str[i]);
            }
        }
    }
    // If exponent > 0
    else if(str[posOfE + 1] == '+')
    {
        if(exp < posOfE - 3)
        // If exponent is small, print decimal point
        {
            exp = exp + 1; // for decimal point location countdown
            for(int i = 1; i < posOfE; i++)
            {
                if(str[i] != '.')
                {
                    printf("%c", str[i]);
                }
                if(exp == 0)
                {
                    printf(".");
                }
                exp--;
            }
        }
        else
        // If exponent is large, print zeros after original base number
        {
            for(int i = 1; i < posOfE; i++)
            {
                if(str[i] != '.')
                {
                    printf("%c", str[i]);
                }
            }
            // Print zeros
            exp = exp - posOfE + 3;
            while(exp > 0)
            {
                printf("0");
                exp--;
            }
        }
    }
    // If exponent == 0
    else if(str[posOfE + 1] == '0')
    {
        printf("1.");
        // Print zeros after decimal point
        // whose number is based on precision of original base
        posOfE = posOfE - 3;
        while(posOfE > 0)
        {
            printf("0");
            posOfE--;
        }
    }

    return 0;
}

