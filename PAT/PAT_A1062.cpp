#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100000;

struct Testee
{
    char id[10];
    int talent;
    int virtue;
    int type;
    int sum;
} testee[MAX], qualified[MAX];

bool cmp(Testee a, Testee b);

int main()
{
    long testeeNum = 0, qualifiedNum = 0;
    int low, high;
    long type1num = 0, type2num = 0, type3num = 0, type4num = 0;

    // Input data
    scanf("%d %d %d", &testeeNum, &low, &high);
    for(int i = 0; i < testeeNum; i++)
    {
        scanf("%s %d %d", &testee[i].id, &testee[i].virtue, &testee[i].talent);
        if(testee[i].virtue >= low && testee[i].talent >= low)
        {
            if(testee[i].virtue >= high && testee[i].talent >= high)
            // testee type No.1
            {
                testee[i].type = 1;
                type1num++;
            }
            else if(testee[i].virtue >= high && testee[i].talent <= high)
            // testee type No.2
            {
                testee[i].type = 2;
                type2num++;
            }
            else if(testee[i].virtue < high && testee[i].talent < high &&
                    testee[i].virtue >= testee[i].talent)
            // testee type No.3
            {
                testee[i].type = 3;
                type3num++;
            }
            else
            // testee type No.4
            {
                testee[i].type = 4;
                type4num++;
            }

            // Calculate sum number
            testee[i].sum = testee[i].talent + testee[i].virtue;
        }
        else
        // Testee is not qualified
        {
            testee[i].type = 5;
        }

        // Store qualified testees into qualified[]
        if(testee[i].type != 5)
        {
            qualified[qualifiedNum] = testee[i];
            qualifiedNum++;
        }
    }

    // Sort testee rank
    sort(qualified, qualified+qualifiedNum, cmp);

    // Print result
    printf("%d\n", qualifiedNum);
    for(int i = 0; i < qualifiedNum; i++)
    {
        printf("%s %d %d\n", qualified[i].id, qualified[i].virtue, qualified[i].talent);
    }

    return 0;
}

bool cmp(Testee a, Testee b)
{
   if(a.type != b.type)
   {
       return a.type < b.type;
   }
   else if(a.sum != b.sum)
   {
       return a.sum > b.sum;
   }
   else if(a.virtue != b.virtue)
   {
       return a.virtue > b.virtue;
   }
   else if(a.talent != b.talent)
   {
       return a.talent > b.talent;
   }
   else
   {
       return strcmp(a.id, b.id) < 0;
   }
}


