#include <cstdio>

using namespace std;

float FindMax(float W, float T, float L);

int main()
{
    float odds[3][3] = {0};
    float maxProfits[3] = {0};
    float totalMaxProfit;

    for(int i = 0; i < 3; i++)
    {
        scanf("%f %f %f", &odds[i][0], &odds[i][1], &odds[i][2]);
        maxProfits[i] = FindMax(odds[i][0], odds[i][1], odds[i][2]);
    }
    totalMaxProfit = (maxProfits[0] * maxProfits[1] * maxProfits[2] * 0.65 - 1) * 2;
    printf("%.2f", totalMaxProfit);
}

float FindMax(float W, float T, float L)
{
    float tempMax = W;
    char typeChar = 'W';

    if(T > tempMax)
    {
        tempMax = T;
        typeChar = 'T';
    }
    if(L > tempMax)
    {
        tempMax = L;
        typeChar = 'L';
    }

    printf("%c ", typeChar);
    return tempMax;
}
