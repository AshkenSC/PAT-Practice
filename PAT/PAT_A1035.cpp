#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct User
{
    char name[20];
    char pwd[20];
    bool isModified;

    User()
    {
        isModified = false;
    }
}user[1010];

int main()
{
    int caseNum;
    int modCount = 0;
    User modified[1010];

    // Data input
    scanf("%d", &caseNum);
    for(int i = 0; i < caseNum; i++)
    {
        scanf("%s %s", user[i].name, user[i].pwd);
    }
    
    // Scan and modify
    for(int i = 0; i < caseNum; i++)
    {
        for(int j = 0; j < strlen(user[i].pwd); j++)
        {
            if(user[i].pwd[j] == '1' || user[i].pwd[j] == '0' ||
               user[i].pwd[j] == 'l' || user[i].pwd[j] == 'O')
            {
                user[i].isModified = true;
                if(user[i].pwd[j] == '1')
                {
                    user[i].pwd[j] = '@';
                }
                else if(user[i].pwd[j] == '0')
                {
                    user[i].pwd[j] = '%';
                }
                else if(user[i].pwd[j] == 'l')
                {
                    user[i].pwd[j] = 'L';
                }
                else if(user[i].pwd[j] == 'O')
                {
                    user[i].pwd[j] = 'o';
                }
            }
        }

        if(user[i].isModified == true)
        {
            modCount++;
        }
    }

    // Print results
    // 1. Print statistics
    if(modCount == 0)
    {
        if(caseNum == 1)
        {
            printf("There is 1 account and no account is modified");
        }
        else
        {
            printf("There are %d accounts and no account is modified", caseNum);
        }
    }
    else
    {
        printf("%d\n", modCount);
    }
    // 2. Print modified entries
    for(int i = 0; i < caseNum; i++)
    {
        if(user[i].isModified == true)
        {
            printf("%s %s", user[i].name, user[i].pwd);
            if(i != caseNum - 1)
            {
                printf("\n");
            }
        }
    }

    return 0;
}

