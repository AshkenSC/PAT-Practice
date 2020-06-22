#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int caseNum;
    int minLen = 0;
    int suffixLen = 0;
    bool isSame;
    char line[110][300];
    char tempLine[300];

    // Input
	scanf("%d", &caseNum);
	getchar();
	for(int i = 0; i < caseNum; i++)
	{
	    gets(line[i]);
	    if(strlen(line[i]) > minLen)
        {
            minLen = strlen(line[i]);
        }
	    reverse(line[i], line[i]+strlen(line[i]));
	}

	// Find common suffix
	char temp;
	for(int i = 0; i < minLen; i++)
    {
        temp = line[0][i];
        isSame = true;
        for(int j = 1; j < caseNum; j++)
        {
            if(temp != line[j][i])
            {
                isSame = false;
                break;
            }
        }
        if(isSame == true)
        {
            suffixLen++;
        }
        else
        {
            break;
        }
    }

	// Output result
	if(suffixLen == 0)
	{
	    printf("nai");
	}
	else
	{
	    for(int i = suffixLen - 1; i >= 0; i--)
	    {
	        printf("%c", line[0][i]);
	    }
	}

	return 0;
}
