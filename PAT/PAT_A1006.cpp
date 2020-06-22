#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_RECORD = 1005;

struct Record
{
    char id[20];
    char login[9];
    char logout[9];

    Record()
    {
        strcpy(login, "23:59:59");
        strcpy(logout, "00:00:00");
    }
} records[MAX_RECORD];

int recordCount = 0;

int CompareTime(char* time1, char* time2);

int main()
{
    Record loginFirst, logoutLast;

    scanf("%d", &recordCount);
    for(int i = 0; i < recordCount; i++)
    {
        scanf("%s %s %s", records[i].id, records[i].login, records[i].logout);
        if(CompareTime(records[i].login, loginFirst.login) == -1)
        {
            loginFirst = records[i];
        }
        if(CompareTime(records[i].logout, logoutLast.logout) == 1)
        {
            logoutLast = records[i];
        }
    }
    printf("%s %s", loginFirst.id, logoutLast.id);
}

int CompareTime(char* time1, char* time2)
{
    // If time1 is later than time2 return 1
    // If time1 is earlier than time2 return -1
    // If time1 == time2 return 0

    for(int i=0; i<9; i++)
    {
        if(time1[i] == time2[i])
        {
            continue;
        }
        else if(time1[i] > time2[i])
        {
            return 1;
        }
        else if(time1[i] < time2[i])
        {
            return -1;
        }
    }

    return 0;
}

