// PAT B1031

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const int verify[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {

    int num, illegalNum = 0;
    int z;
    bool isLegal;
    char temp[20], illegalId[105][20];

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%s", temp);

        // judge legality
        z = 0;
        isLegal = true;
        for(int j = 0; j < 17; j++) {
            if(!(temp[j] >= '0' && temp[j] <= '9')) {
                isLegal = false;
                break;
            }
            else {
                z += (temp[j] - '0') * weight[j];
            }
        }
        if(isLegal == true) {
            z = z % 11;
            if(temp[17] != verify[z]) {
                isLegal = false;
            }
        }

        // if the id is illegal, store it
        if(isLegal == false) {
            strcpy(illegalId[illegalNum++], temp);
        }
    }

    // print result
    if(illegalNum > 0) {
        for(int i = 0; i < illegalNum; i++) {
            printf("%s\n", illegalId[i]);
        }
    }
    else {
        printf("All passed");
    }


    return 0;
}







