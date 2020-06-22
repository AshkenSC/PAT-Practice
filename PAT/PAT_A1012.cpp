#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 2005;
char COURSES[4][3] = {" A", " C", " M", " E"};

struct Stu
{
    // student ID
    char id[10];
    // student grades
    // 0: Avg, 1: C, 2: Math, 3: Eng
    int grades[4];
    // student ranks
    int ranks;
} stu[4][MAX];  // Use 4 arrays to store 4 different ranks: A, C, M, E


bool cmpA(Stu a, Stu b);
bool cmpC(Stu a, Stu b);
bool cmpM(Stu a, Stu b);
bool cmpE(Stu a, Stu b);
int Query(char * queryId, Stu * stuList);

int numIn, numQuery;

int main()
{
    // Input data
    scanf("%d %d", &numIn, &numQuery);
    for(int i = 0; i < numIn; i++)
    {
        scanf("%s", &stu[0][i].id);
        for(int j = 1; j <= 3; j++)
        {
            scanf("%d", &stu[0][i].grades[j]);
        }
        // Store total score(instead of average) in grades[0]
        stu[0][i].grades[0] = stu[0][i].grades[1] + stu[0][i].grades[2] + stu[0][i].grades[3];
    }

    // Copy data into the other three arrays
    for(int i = 0; i < numIn; i++)
    {
        stu[1][i] = stu[0][i];
        stu[2][i] = stu[0][i];
        stu[3][i] = stu[0][i];
    }

    // Sort four arrays
    sort(stu[0], stu[0] + numIn, cmpA);
    sort(stu[1], stu[1] + numIn, cmpC);
    sort(stu[2], stu[2] + numIn, cmpM);
    sort(stu[3], stu[3] + numIn, cmpE);
    // Deal with students at the same rank in all the 4 courses
    for(int i = 0; i < 4; i++)
    {
        // Initialize the first place of the 4 courses as 1
        stu[i][0].ranks = 1;
        // Calculate ranks of latter students
        for(int j = 1; j < numIn; j++)
        {
            if(stu[i][j].grades[i] == stu[i][j-1].grades[i])
            // If current student's grade is the same as the prior student
            // Set the rank same as the prior one
            {
                stu[i][j].ranks = stu[i][j-1].ranks;
            }
            else
            // Set the rank as current array location +1
            {
                stu[i][j].ranks = j + 1;
            }
        }
    }

    // Query and print results
    char course[5] = "N/A";
    char queryId[10];
    int rankOut = 0, rankTemp = 0;
    for(int i = 0; i < numQuery; i++)
    {
        scanf("%s", &queryId);
        for(int j = 0; j < 4; j++)
        {
            // Search the i-th student in course No.j rank array
            rankTemp = Query(queryId, stu[j]);
            if(j == 0)
                // If currently searching for the first course
            {
                rankOut = rankTemp;
                strcpy(course, COURSES[j]);
            }
            else
                // Searching for the the second/third/... course
            {
                if(rankTemp != 0 && rankTemp < rankOut)
                {
                    rankOut = rankTemp;
                    strcpy(course, COURSES[j]);
                }
            }
        }

        // Print result
        if(rankOut != 0)
        {
            printf("%d%s\n", rankOut, course);
        }
        else
        {
            printf("N/A\n");
        }
    }

    return 0;
}

int Query(char * queryId, Stu * stuList)
{
    int i;
    // Find student's rank
    for(i = 0; i < numIn; i++)
    {
        if(strcmp(stuList[i].id, queryId) == 0)
        {
            break;
        }
    }

    // Return rank value
    if(i != numIn)
        // id found, return current location in array
    {
        return stuList[i].ranks;
    }
    else
        // id not found
    {
        return 0;
    }
}

bool cmpA(Stu a, Stu b)
{
    return a.grades[0] > b.grades[0];
}

bool cmpC(Stu a, Stu b)
{
    return a.grades[1] > b.grades[1];
}

bool cmpM(Stu a, Stu b)
{
    return a.grades[2] > b.grades[2];
}

bool cmpE(Stu a, Stu b)
{
    return a.grades[3] > b.grades[3];
}


