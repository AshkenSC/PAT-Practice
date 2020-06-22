// PAT B1047

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct Team {
    int teamId;
    int grades;
} teams[1001];

bool cmp (Team a, Team b);

int main() {

    // declare variables and initialize array
    int memNum, teamId, memId, memGrades;
    for(int i = 0; i < 1001; i++) {
        teams[i].teamId = i;
        teams[i].grades = 0;
    }

    // input data
    scanf("%d", &memNum);
    for(int i = 0; i < memNum; i++) {
        scanf("%d-%d %d", &teamId, &memId, &memGrades);
        teams[teamId].grades += memGrades;
    }

    // sort and print result
    sort(teams + 1, teams + 1001, cmp);
    printf("%d %d", teams[1].teamId, teams[1].grades);

    return 0;
}

bool cmp (Team a, Team b) {
    return a.grades > b.grades;
}



