#include <cstdio>

using namespace std;

int caseCount;
long long numA, numB, numC, sumAB;

void JudgeFunc(int caseNum, long long numA, long long numB, long long numC);

int main()
{
	scanf("%d", &caseCount);
	for (int i=1; i<=caseCount; i++)
	{
		scanf("%lld %lld %lld", &numA, &numB, &numC);
		JudgeFunc(i, numA, numB, numC);
	}
	return 0;
} 

void JudgeFunc(int caseNum, long long numA, long long numB, long long numC)
{
	bool flag;
	sumAB = numA + numB;
	if(numA > 0 && numB > 0 && sumAB < 0)
	{
		flag = true;
	}
	else if (numA < 0 && numB < 0 && sumAB >= 0)
	{
		flag = false;
	}
	else if(sumAB > numC)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	
	if(flag == true)
	{
		printf("Case #%d: true\n", caseNum);
	}
	else
	{
		printf("Case #%d: false\n", caseNum);
	}
}
