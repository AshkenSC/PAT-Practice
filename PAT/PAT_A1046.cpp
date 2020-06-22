#include <cstdio> 
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int numExit;
int exitDist[MAXN];
int one_to_i_Dist[MAXN];
int sumDist = 0;

int numTest;
int startExits[MAXN];
int endExits[MAXN];

void Input();
int Calc(int startExit, int endExit);
int main()
{
	Input();
	for(int i = 1; i <= numTest; i++)
	{
		printf("%d\n", Calc(startExits[i], endExits[i]));
	}
	return 0;
}

// Process input
void Input()
{
	// Input number of exits
	scanf("%d", &numExit);
	// Input adjacent distances
	for(int i = 1; i <= numExit; i++)
	{
		scanf("%d", &exitDist[i]);
		sumDist += exitDist[i];
		one_to_i_Dist[i] = sumDist;
	}
	// Input number of tests
	scanf("%d", &numTest);
	// Input exit No. in every test case
	for(int i = 1; i <= numTest; i++)
	{
		scanf("%d %d", &startExits[i], &endExits[i]);
	}
}

// Calculate and return the shortest distance 
int Calc(int startExit, int endExit)
{
	// Make sure start No. is less than end No.
	if(startExit > endExit)
	{
		swap(startExit, endExit);
	}
	
	// Calculate distance from two diffenrent directions
	int dist_clockwise, dist_antiClockwise;
	dist_clockwise = one_to_i_Dist[endExit - 1] - one_to_i_Dist[startExit - 1];
	dist_antiClockwise = sumDist - dist_clockwise; 
	
	// Compare and return the smaller one
	if(dist_clockwise < dist_antiClockwise)
	{
		return dist_clockwise;
	}
	else
	{
		return dist_antiClockwise;
	}
}
