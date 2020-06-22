#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    long long galleon =  0; int sickle = 0, knut = 0;
    long long galleon1; int sickle1, knut1;
    long long galleon2; int sickle2, knut2;
    long long temp;

    // Input data
    scanf("%lld.%d.%d", &galleon1, &sickle1, &knut1);
    scanf("%lld.%d.%d", &galleon2, &sickle2, &knut2);

    // Calculate summation
    knut = knut1 + knut2;
    temp = knut;
    knut %= 29;
    sickle += temp / 29;

    sickle += sickle1 + sickle2;
    temp = sickle;
    sickle %= 17;
    galleon += temp / 17;

    galleon += galleon1 + galleon2;

    // Print result
    printf("%lld.%d.%d", galleon, sickle, knut);

    return 0;
}
