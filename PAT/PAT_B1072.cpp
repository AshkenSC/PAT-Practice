// PAT B1072

/*
4 2
2334 6766
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333

*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int stuNum, bannedNum;
    int bannedItems[9999] = {0};
    int totalBadStuNum = 0, totalBannedItemNum = 0;

    scanf("%04d%04d", &stuNum, &bannedNum);
    for(int i = 0; i < bannedNum; i++) {
        int tempItemId;
        scanf("%d", &tempItemId);
        bannedItems[tempItemId] = 1;
    }
    char stuName[5];
    int stuItemNum;
    int stuItemId;
    bool isNamePrinted, isStudentBad;
    for(int i = 0; i < stuNum; i++) {
        isNamePrinted = false;
        isStudentBad = false;
        scanf("%s %d", stuName, &stuItemNum);
        for(int j = 0; j < stuItemNum; j++) {
            scanf("%d", &stuItemId);
            if(bannedItems[stuItemId] == 1) {
                isStudentBad = true;
                if(isNamePrinted == false) {
                    printf("%s:", stuName);
                    isNamePrinted = true;
                }
                printf(" %04d", stuItemId);
                totalBannedItemNum++;
            }
        }
        if(isStudentBad == true) {
            totalBadStuNum++;
            printf("\n");
        }
    }

    printf("%d %d", totalBadStuNum, totalBannedItemNum);

    return 0;
}

