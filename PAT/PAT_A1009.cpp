#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    double coefA[1001] = {0.0};
    double product[2001] = {0.0};

    // Input polynomial A
    int nonzeroA, expA;
    scanf("%d", &nonzeroA);
    for(int i = 0; i < nonzeroA; i++)
    {
        scanf("%d", &expA);
        scanf("%lf", &coefA[expA]);
    }

    // Input Polynomial B and calculate
    int nonzeroB, expB;
    double coefB;
    scanf("%d", &nonzeroB);
    for(int j = 0; j < nonzeroB; j++)
    {
        scanf("%d", &expB);
        scanf("%lf", &coefB);
        for(int i = 0; i < 1001; i++)
        {
            product[expB + i] += coefB * coefA[i];
        }
    }

    // Count nonzero items
    int nonzero = 0;
    for(int i = 0; i <= 2000; i++)
    {
        if(product[i] != 0.0)
        {
            nonzero++;
        }
    }
    printf("%d", nonzero);

    // Print result
    for(int i = 2000; i >= 0; i--)
    {
        if(product[i] != 0.0)
        {
            printf(" %d %.1lf", i, product[i]);
        }
    }

    return 0;
}

