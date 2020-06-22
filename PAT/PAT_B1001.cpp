#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int step = 0;

    scanf("%d", &num);
    while(num != 1)
    {
        if(num % 2 == 0)
        {
            num = num / 2;
        }
        else
        {
            num = (num * 3 + 1) / 2;
        }
        step++;
    }

    printf("%d", step);

    return 0;
}

