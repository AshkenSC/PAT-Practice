#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct Record
{
    char id[7];
    char name[10];
    int grade;
    long idInt;
} records[100500];

int num;    // the number of records
int col;    // sort according to which column

bool cmp(Record a, Record b);

int main()
{
    // data input
    scanf("%d %d", &num, &col);
    for(int i = 0; i < num; i++)
    {
        scanf("%s %s %d", &records[i].id, &records[i].name, &records[i].grade);
        for(int j = 0; j < 6; j++)
        // transfer id to integer for sorting
        {
            records[i].idInt += (records[i].id[j] - '0') * pow(10, 5 - j);
        }
    }

    // sort and print result
    sort(records, records + num, cmp);
    for(int i = 0; i < num; i++)
    {
        printf("%s %s %d\n", records[i].id, records[i].name, records[i].grade);
    }

    return 0;
}

bool cmp(Record a, Record b)
{
    if(col == 1)
    // sort according to id
    {
        return a.idInt < b.idInt;
    }
    else if(col == 2)
    // sort according to name
    {
        if(strcmp(a.name, b.name) == 0)
        // if the two names are identical
        {
            return a.idInt < b.idInt;
        }
        else
        {
            return (strcmp(a.name, b.name) < 0);
        }
    }
    else if(col == 3)
    // sort according to grades
    {
        if(a.grade == b.grade)
        // if the grades are identical
        {
            return a.idInt < b.idInt;
        }
        else
        {
            return a.grade < b.grade;
        }
    }
}

