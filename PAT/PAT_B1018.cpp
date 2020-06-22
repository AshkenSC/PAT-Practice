// PAT B1018
// one take! 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct winGesture {
    char gesture;
    int times = 0;
} aMost[3], bMost[3];

int Judge(char a, char b);
bool cmp(winGesture a, winGesture b);

int main() {
    int num;
    char a, b;
    int aWin = 0, bWin = 0, draw = 0;
    // arrays that record gestures a and b have used to win
    aMost[0].gesture = 'B';     bMost[0].gesture = 'B';
    aMost[1].gesture = 'C';     bMost[1].gesture = 'C';
    aMost[2].gesture = 'J';     bMost[2].gesture = 'J';

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("\n%c %c", &a, &b);
        if(Judge(a, b) == -1) {
            aWin++;
            if(a == 'B') {
                aMost[0].times++;
            }
            else if(a == 'C') {
                aMost[1].times++;
            }
            else if(a == 'J') {
                aMost[2].times++;
            }
        }
        else if(Judge(a, b) == 1) {
            bWin++;
            if(b == 'B') {
                bMost[0].times++;
            }
            else if(b == 'C') {
                bMost[1].times++;
            }
            else if(b == 'J') {
                bMost[2].times++;
            }
        }
        else if(Judge(a, b) == 0) {
            draw++;
        }
    }

    sort(aMost, aMost + 3, cmp);
    sort(bMost, bMost + 3, cmp);

    printf("%d %d %d\n", aWin, draw, bWin);
    printf("%d %d %d\n", bWin, draw, aWin);
    printf("%c %c", aMost[0].gesture, bMost[0].gesture);

    return 0;
}

int Judge(char a, char b) {

    // in input, B means paper, C means rock, J means scissors
    // in output, -1 means a wins, 0 means draw, 1 means b wins

    if(a == 'B') {
        if(b == 'B') return 0;        // a paper, b paper
        else if(b == 'C') return -1;  // a paper, b rock
        else if(b == 'J') return 1;   // a paper, b scissors
    }
    else if(a == 'C') {
        if(b == 'B') return 1;        // a rock, b paper
        else if(b == 'C') return 0;   // a rock, b rock
        else if(b == 'J') return -1;  // a rock, b scissors
    }
    else if(a == 'J') {
        if(b == 'B') return -1;       // a scissors, b paper
        else if(b == 'C') return 1;   // a scissors, b rock
        else if(b == 'J') return 0;   // a scissors, b scissors
    }
}

bool cmp(winGesture a, winGesture b) {
    if(a.times != b.times) {
        return a.times > b.times;
    }
    else {
        return a.gesture < b.gesture;
    }
}



