// PAT B1064

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int num, inputNumber;
    int tempFriendId;
    set<int> friendIdSet;

    // data input
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &inputNumber);
        tempFriendId = 0;
        while(inputNumber > 0) {
            tempFriendId += inputNumber % 10;
            inputNumber /= 10;
        }
        friendIdSet.insert(tempFriendId);
    }

    // print result
    printf("%d\n", friendIdSet.size());
    for(set<int>::iterator it = friendIdSet.begin(); it != friendIdSet.end(); it++) {
        if(it == friendIdSet.begin()) {
            printf("%d", *it);
        }
        else {
            printf(" %d", *it);
        }
    }

    return 0;
}

