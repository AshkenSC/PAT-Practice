#include <cstdio>
#include <iostream>

using namespace std;

/* Test case:

4 4 0.5 2 5.6 1 -2.7 0 3.6
3 3 -2.1 2 -5.6 1 2.7

*/

const int MAX_EXP = 1010;
double polyA[MAX_EXP] = {0.0};
double polyB[MAX_EXP] = {0.0};
double polySum[MAX_EXP] = {0.0};
int sumTermCount = 0;

int main()
{
	int termCount, tempExp;
	double tempCoef;

	// Input polynomial A
	scanf("%d", &termCount);
	for(int i = 0; i < termCount; i++)
	{
		scanf("%d %lf", &tempExp, &tempCoef);
		polyA[tempExp] = tempCoef;
	}

	// Input polynomial B
	scanf("%d", &termCount);
	for(int i = 0; i < termCount; i++)
	{
		scanf("%d %lf", &tempExp, &tempCoef);
		polyB[tempExp] = tempCoef;
	}

	// Calculate
	for(int i = 0; i <= 1000; i++)
	{
		polySum[i] = polyA[i] + polyB[i];
		if(polySum[i] != 0)
		{
			sumTermCount++;
		}
	}

	// Output
	printf("%d", sumTermCount);
	for(int i = 1000; i >= 0; i--)
	{
		if(polySum[i] != 0)
		{
			printf(" %d %.1lf", i, polySum[i]);
		}
	}

	return 0;
}
