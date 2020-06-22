#include <cstdio>
const int N = 54;
int start[N+1], end[N+1], order[N+1];
int shuffleTime;

void Init();
void Shuffle();
void Print();
 
int main()
{
	Init();
	Shuffle();
	Print();
	
	return 0;
}

// Input and init
void Init()
{
	
	scanf("%d", &shuffleTime);
	for(int i=1; i<=N; i++)
	{
		start[i] = i;	
	}
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &order[i]);
	}	
}

// Shuffle
void Shuffle()
{
	for (int step=0; step<shuffleTime; step++)
	{
		for(int i=1; i<=N; i++)
		{
			//end[order[i]] = i;
			end[order[i]] = start[i];
		}
		for(int i=1; i<=N; i++)
		{
			start[i] = end[i];
		}
	}
}

// Output
void Print()
{
	char shape[5] = {'S', 'H', 'C', 'D', 'J'};
	for(int i=1; i<=N; i++)
	{
		start[i]--;
		printf("%c%d", shape[start[i] / 13], start[i]%13+1);
		if(i < N)
		{
			printf(" ");
		}
	}
}
