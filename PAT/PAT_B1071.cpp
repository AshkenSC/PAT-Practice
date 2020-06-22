// PAT 

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int tokenLeft, gameNum;
    int givenNumber, bigSmall, guessNumber, betAmount;

    scanf("%d%d", &tokenLeft, &gameNum);
    for(int i = 0; i < gameNum; i++) {
        scanf("%d%d%d%d", &givenNumber, &bigSmall, &betAmount, &guessNumber);
        if(betAmount > tokenLeft) {
            printf("Not enough tokens.  Total = %d.\n", tokenLeft);
            continue;
        }
        else {
            if((guessNumber > givenNumber) == bigSmall) {
                tokenLeft += betAmount;
                printf("Win %d!  Total = %d.\n", betAmount, tokenLeft);
            }
            else {
                tokenLeft -= betAmount;
                printf("Lose %d.  Total = %d.\n", betAmount, tokenLeft);
                if(tokenLeft == 0) {
                    printf("Game Over.\n");
                    break;
                }
            }
        }
    }

    return 0;
}

