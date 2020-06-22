#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_LENGTH = 70;
char DAYS[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

using namespace std;

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH], str3[MAX_LENGTH], str4[MAX_LENGTH];
    int len1, len2, len3, len4;
    int day, hour, minute;

    // Strings input
    scanf("%s %s %s %s", &str1, &str2, &str3, &str4);
    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);
    len4 = strlen(str4);

    // Find time in strings
    int i;
    // Deal with days
    for(i = 0; i < min(len1, len2); i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'G' &&
           str1[i] == str2[i])
        {
            day = str1[i] - 'A';
            break;
        }
    }
    // Deal with hours
    for(i++; i < min(len1, len2); i++)
    {
        if(str1[i] == str2[i])
        {
            if(str1[i] >= '0' && str1[i] <= '9')
            {
                hour = str1[i] - '0';
                break;
            }
            else if(str1[i] >= 'A' && str1[i] <= 'N')
            {
                hour = str1[i] - 'A' + 10;
                break;
            }
        }
    }
    // Deal with minutes
    for(i = 0; i < min(len3, len4); i++)
    {
        if(str3[i] == str4[i])
        {
            if(str3[i] >= 'A' && str3[i] <= 'Z' || str3[i] >= 'a' && str3[i] <= 'z')
            {
                minute = i;
                break;
            }
        }
    }

    // Print results
    printf("%s ", DAYS[day]);
    printf("%02d:%02d", hour, minute);

    return 0;
}

