// PAT B1046

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int num, aSay, aDo, bSay, bDo;
    int aDrink = 0, bDrink = 0;

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d %d %d %d", &aSay, &aDo, &bSay, &bDo);
        if(aSay + bSay == aDo && aSay + bSay != bDo) {
            bDrink++;
        }
        else if(aSay + bSay == bDo && aSay + bSay != aDo) {
            aDrink++;
        }
        else {
            continue;
        }
    }

    printf("%d %d", aDrink, bDrink);

    return 0;
}



