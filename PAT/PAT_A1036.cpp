#include <cstdio>

using namespace std;

const int MAX_STU_NUM = 1005;

struct Student
{
    char name[20];
    char gender;
    char ID[20];
    int grade;

    Student()
    {
        gender = 'A';
    }
} stuList[MAX_STU_NUM];

// Variables that save highest grade among girls and lowest among boys
Student highFemale, lowMale;
// Judge if the comparison is unavailable
bool isNA = false;

void InputProfile();
void PrintResult();

int main()
{

    highFemale.grade = -1;  // Set initial value to -1 so higher grades can be stored
    lowMale.grade = 101;    // lowMale.grade is set to 101 for similar reason

    InputProfile();
    PrintResult();

    return 0;
}

void InputProfile()
{
    int caseCount;

    scanf("%d", &caseCount);
    for(int i=0; i < caseCount; i++)
    {
        scanf("%s %c %s %d", &stuList[i].name, &stuList[i].gender, &stuList[i].ID, &stuList[i].grade);
        if(stuList[i].gender == 'M' && stuList[i].grade < lowMale.grade)
        {
            lowMale = stuList[i];
        }
        else if(stuList[i].gender == 'F' && stuList[i].grade > highFemale.grade)
        {
            highFemale = stuList[i];
        }
    }
}

void PrintResult()
{
    // Print highest grade female
    if(highFemale.gender == 'A')
    {
        isNA = true;
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", highFemale.name, highFemale.ID);
    }

    // Print lowest grade male
    if(lowMale.gender == 'A')
    {
        isNA = true;
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", lowMale.name, lowMale.ID);
    }

    // Print comparison result
    if(isNA == false)
    {
        printf("%d", highFemale.grade - lowMale.grade);
    }
    else
    {
        printf("NA");
    }
}
