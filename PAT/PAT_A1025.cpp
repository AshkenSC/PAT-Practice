#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Info
{
    char id[15];
    int grade;
    int locationId;
    int localRank;

}stu[30010];

bool cmp(Info a, Info b);

int main()
{
    int stuTotalNum = 0;    // total number of testee
    int locationNum;    // total number of test location
    int localStuNum;    // number of testee in a single test location

    scanf("%d", &locationNum);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", localStuNum);
        for(int j=0; j<localStuNum; j++)
        {
            scanf("%s %d", stu[stuTotalNum].id, &stu[stuTotalNum].grade);
            // Current student's test location id is i
            stu[stuTotalNum].locationId = i;
            stuTotalNum++;
        }
        // Sort students in test location i, range is set according to localStuNum
        sort(stu + stuTotalNum - localStuNum, stu + stuTotalNum, cmp);
        // Set the 1st of current test location rank to 1
        stu[stuTotalNum - k].localRank = 1;
        // For the rest of current test location
        for(int j=stuTotalNum-localStuNum+1; j<stuTotalNum; j++)
        {
            if(stu[j].grade == stu[j-1].grade)
            // If current student's grade is equal to the prior one
            {
                stu[j].localRank = stu[j-1].localRank;
            }
            else
            // else set local rank to the number of students before the current one
            {
                stu[j].localRank = j + 1 - (stuTotalNum - localStuNum);
            }
        }
<<<<<<< HEAD
    }

    // Print total number of students
    printf("%d\n", stuTotalNum);
    // Sort all the students
    sort(stu, stu + stuTotalNum, cmp);
    int currentStuRank = 1;
    for(int i=0; i<stuTotalNum; i++)
    {
        if(i > 0 && stu[i].grade != stu[i - 1].grade)
        // If current student's grade is different from prior one
        // update current student's rank
        {
            currentStuRank = i + 1;
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", currentStuRank, stu[i].locationId, stu[i].localRank);
=======
>>>>>>> d3e173d2f49aa200492a4da68a68076079bb091e
    }



    return 0;
}

bool cmp(Info a, Info b)
{
    if(a.grade != b.grade)
    {
        return a.grade > b.grade
    }
    else
    {
        return strcmp(a.id, b.id);
    }
}
