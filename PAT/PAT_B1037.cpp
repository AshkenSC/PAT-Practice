// PAT B1037

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    long long change;
    long long pGalleon, aGalleon;
    int pSickle, aSickle;
    int pKnut, aKnut;

    scanf("%lld.%d.%d", &pGalleon, &pSickle, &pKnut);
    scanf("%lld.%d.%d", &aGalleon, &aSickle, &aKnut);

    change = (aGalleon * 17 * 29 + aSickle * 29 + aKnut) -
             (pGalleon * 17 * 29 + pSickle * 29 + pKnut);

    if(change < 0) {
        printf("-");
        change = 0 - change;
    }
    printf("%lld.", change / 17 / 29);  // print galleon
    change = change % (17 * 29);
    printf("%d.", change / 29);         // print sickle
    change = change % 29;
    printf("%d", change);               // print knut

    return 0;
}



