// PAT B1076

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int num;
    char answers[4][4];
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%s", answers[j]);
            if(answers[j][2] == 'T') {
                printf("%d", answers[j][0] - 'A' + 1);
            }
            if(j == 3) {
                scanf("\n");
            }
        }
    }

    return 0;
}

