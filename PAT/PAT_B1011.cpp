// PAT B1011

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
   int caseNum;
   long long a, b, c;

   cin >> caseNum;
   for(int i = 0; i < caseNum; i++) {
       cin >> a >> b >> c;
       if(a + b > c) {
           printf("Case #%d: true\n", i+1);
       }
       else {
           printf("Case #%d: false\n", i+1);
       }
   }

    return 0;
}