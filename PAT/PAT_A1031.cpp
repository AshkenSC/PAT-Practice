#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 90;
char inputStr[MAX_LENGTH];
int verticalLen, bottomLen;

void InputProcess();
void PrintU();

int main()
{
    InputProcess();
    PrintU();

    return 0;
}

void InputProcess()
{
    // Input string and calculate shape of U
    scanf("%s", &inputStr);
    for(int i=0; i<strlen(inputStr); i++)
    {
        verticalLen = i;
        bottomLen = strlen(inputStr)+2 - verticalLen*2;
        if(bottomLen < verticalLen)
        // Roll back the values
        {
            verticalLen = i - 1;
            bottomLen = strlen(inputStr)+2 - verticalLen*2;
            break;
        }
    }
}

void PrintU()
{
    // Print vertical lines of U
    for(int i=0; i<verticalLen-1; i++)
    {
        printf("%c", inputStr[i]);
        for(int j=0; j<bottomLen-2; j++)
        {
            printf(" ");
        }
        printf("%c\n", inputStr[strlen(inputStr) - (i+1)]);
    }

    // Print bottom line of U
    for(int i=verticalLen-1; i <= verticalLen-1 + bottomLen-1; i++)
    {
        printf("%c", inputStr[i]);
    }

}
