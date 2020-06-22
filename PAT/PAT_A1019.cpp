#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 50;

class Target
{
    public:
    int targetNum[MAX_LENGTH];
    int digit;
};

Target Convert(int decimal, int base);
bool Judge(Target target);

int main()
{
    Target target;
    int decimal, base;

    scanf("%d %d", &decimal, &base);
    target = Convert(decimal, base);

    // Judge and print if it is palindromic
    if(Judge(target))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    // Print target number
    if(target.digit == 1)
    {
        printf("%d", target.targetNum[0]);
    }
    else
    {
        for(int i=0; i<target.digit; i++)
        {
            printf("%d", target.targetNum[i]);
            if(i != target.digit-1)
            {
                printf(" ");
            }
        }
    }

    return 0;
}

// Convert decimal number to target base
Target Convert(int decimal, int base)
{
    stack<int> targetStack;
    Target target;
    int decimalTemp = decimal;

    do
    {
        targetStack.push(decimalTemp % base);
        decimalTemp = decimalTemp / base;
    }
    while(decimalTemp >= base);
    if(decimal >= base)
    {
        targetStack.push(decimalTemp);
    }

    for(target.digit=0; targetStack.empty() == false; target.digit++)
    {
        target.targetNum[target.digit] = targetStack.top();
        targetStack.pop();
    }

    return target;
}

// Judge if it is a palindromic number
bool Judge(Target target)
{
    if(target.digit == 1)
    {
        return true;
    }

    for(int i=0; i<=target.digit-1-i; i++)
    {
        if(target.targetNum[i] == target.targetNum[target.digit-1-i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
